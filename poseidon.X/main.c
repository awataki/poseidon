/* 
 * File:   main.c
 * Author: awataki
 *
 * Created on 17 January 2020, 11:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic.h>
#include <xc.h>

#include "Domain/buzzer.h"
#include "Domain/PracticeBox.h"
#include "Domain/lcd_disp.h"
#include "Domain/sensor.h"
#include "AppLogic/menu.h"
#include "AppLogic/stop.h"
#include "AppLogic/wash.h"
#include "Model/HardWareState.h"
#include "Model/Flags.h"

/* CONFIGRATION */
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config LVP = OFF
#pragma config WRT = OFF
#pragma config BOR4V = BOR40V

#define SEC 100
#define MIN 60*SEC
#define _XTAL_FREQ 800000


#define SEC_MAX     32  /* 0.6107usx256x64=10ms */
int     sec=0;
int     t_int_flag=0;
hard_ware_states hw;
flags f;

#pragma INTERRUPT rtcc_isr

static void __interrupt () rtcc_isr( void ) {
        sec ++;
    if( sec == SEC_MAX ){
        sec = 0;
        t_int_flag ++;
    }
}

static void pic_init() {
//       	OSCCON = 0x70;		// INTOSC 8MHz
        PSTRCON = 0x00;     // assigned to port pin

        /* Set Port B*/
   	ANSELH  = 0x00;     // AN Disable (RB5-RB0)
        WPUB = 0x00;        // Pull-up disable
        INTCON = 0x00;      // Intrauppt disable
        IOCB = 0x00;        // Intrauppt charge disable
        CCP1CON = 0x00;
        CM2CON1 = 0x02;
        OPTION_REG = 0xFF;  // Pull-up disable

    	TRISB = 0xFF;       // IN
//        PORTB = 0x11;       // High


        /* Set Port C */
        RCSTA = 0x00;       // Serial disable (RC7-6)
        SSPCON = 0x00;      // Serial disable (RC5-4)

        TRISC = 0x00;       // OUT
        PORTC = 0x00;       // Low

        /* Set Port D config */
        TRISD = 0xC0;       // bit 0-5 OUT, bit6-7 IN
}

void init_hardwares(){
    practice_Box_init();
    init_lcd();
    sensor_init();
}

void init_hardware_states(hard_ware_states *hw){
    (*hw).POWER_SW = 0;
    (*hw).STOP_SW = 0;
    (*hw).MENU_SW = 0;
}

int main(int argc, char** argv) {
    int remain = 0;
    pic_init();
    init_hardwares();
    init_hardware_states(&hw);
    init_flag(&f);
    f.power = 1;
    locate(0,0);
    char s[] = "Power ON";
    write_str(s);
    print_menu(&f);
    while(1){
        //update hardwares
        update_menu_hardware_status(&hw);
        update_stop_hardware_status(&hw);
        update_wash_hardware_status(&hw);
        
        
        disp_number(hw.MENU_SW,0,0);
        // メニュー送り
        if(f.power && hw.MENU_SW && !f.is_washing){
            next_menu(&f);
            __delay_ms(300); 
        }
        
        // 行程送り
        if(f.power && hw.PROCCESS_SW && !f.is_washing){
            next_process(&f);
            __delay_ms(300); 
        }
        
        // 洗濯スタート
        if(f.power && hw.START_SW && !f.is_washing){
            start_wash(&hw,&f);
            f.reservation_at = 0;
            t_int_flag = 0;
            __delay_ms(300); 
        }
        
        // 洗濯ストップ
        if(f.power && hw.START_SW && f.is_washing){
            stop_wash(&hw,&f);
            f.in_progress = 0;
            __delay_ms(300); 
        }
        
        // 予約
        if(f.power && hw.RESERVATION_SW && !f.is_washing){
            reservation_wash(&f);
            t_int_flag = 0;
            __delay_ms(300); 
        }
        
        // 残り時間の計算
        if (f.reservation_at != 0 && remain != (f.reservation_at * 60) - (t_int_flag/MIN)){
            remain = (f.reservation_at * 60) - (t_int_flag/MIN);
            // 更新
            locate(8,4);
            char t = '0' + remain/60;
            write_char(t);
        }else if (f.is_washing && remain != f.total_time - (t_int_flag/MIN)){
            remain = f.total_time - (t_int_flag / MIN);
            // 更新
            locate(12,2);
            char time[2];
            char ten = '0' + remain/10;
            char one = '0' + remain%10;
            time[0] = ten;
            time[1] = one;
            write_str(time);
        }
        
        // 予約時間が来たらスタート
        if( remain < 0 && f.reservation_at != 0){
            start_wash(&hw,&f);
        }
        
        // 終了
        if (f.is_washing && remain >= f.total_time){
             stop_wash(&hw,&f);
            f.in_progress = 0;
            buzzer(SOUND_ON);
            __delay_ms(100);
            buzzer(SOUND_OFF);
        }
        
        // 電源
        if(hw.POWER_SW){
            if(f.power){
                stop_wash(&hw,&f);
                f.power = 0;
                locate(0,0);
                char msg[] = "POWER OFF";
                write_str(msg);
                __delay_ms(300); 
            }else{
                f.power = 1;
                locate(0,0);
                char msg[] = "POWER ON ";
                write_str(msg);
                __delay_ms(300); 
            }
        }
    }
    
    return 0;
}

