#include <string.h>
#include "menu.h"
#include "../Domain/switch.h"
#include "../Model/Switch.h"
#include "../Model/Process.h"
#include "../Model/Course.h"
#include "../AppLogic/wash.h"
#include "../Domain/lcd_disp.h"

#define COURSEX 11
#define COURSEY 1
#define PROCESSX 13
#define PROCESSY 2
#define RESVX 9
#define RESVY 3

void update_menu_hardware_status(hard_ware_states *hw){
    (*hw).POWER_SW = get_switch_state(POWER);
    (*hw).PROCCESS_SW = get_switch_state(PROCESS);
    (*hw).STOP_SW = get_switch_state(STOP);
    (*hw).START_SW = get_switch_state(START);
    (*hw).MENU_SW = get_switch_state(COURSE);
    (*hw).RESERVATION_SW = get_switch_state(RESERVATION);
};

void next_menu(flags *f){
    int now = (*f).selecting_course;
    if(now == 2){
        now = 0;
    }else{
        ++now;
    }
    switch (now){
        case NOMAL:
            (*f).wash_time = 10;
            (*f).rinse_time = 5;
            (*f).rinse_count = 2;
            (*f).spin_time = 10;
            break;
        case SPPEDY:
            (*f).wash_time = 6;
            (*f).rinse_time = 3;
            (*f).rinse_count = 2;
            (*f).spin_time = 3;
            break;
        case STRONG:
            (*f).wash_time = 14;
            (*f).rinse_time = 5;
            (*f).rinse_count = 3;
            (*f).spin_time = 11;
            break;
    }
    (*f).selecting_course = now;
    print_menu(f);
};

void next_process(flags *f){
    int now = (*f).selecting_process;
    if(now == 3){
        now = 0;
    }else{
        ++now;
    }
    
    (*f).progress_time[0] = 0; // W
    (*f).progress_time[1] = 0; // R
    (*f).progress_time[2] = 0; // s

    switch(now){
        case WRS:
            (*f).progress_time[0] = (*f).wash_time;
            (*f).progress_time[1] = (*f).rinse_time * (*f).rinse_count;
            (*f).progress_time[2] = (*f).spin_time;
            break;
        case RS:
            (*f).progress_time[0] = 0;
            (*f).progress_time[1] = (*f).rinse_time * (*f).rinse_count;
            (*f).progress_time[2] = (*f).spin_time;
            break;
        case R:
            (*f).progress_time[0] = 0;
            (*f).progress_time[1] = (*f).rinse_time * (*f).rinse_count;
            (*f).progress_time[2] = 0;
            break;
        case S:
            (*f).progress_time[0] = 0;
            (*f).progress_time[1] = 0;
            (*f).progress_time[2] = (*f).spin_time;
            break;
    }
    (*f).selecting_process = now;
    print_menu(f);
};

void reservation_wash(flags *f){
    if((*f).reservation_at == 5){
        (*f).reservation_at = 0;
    }else{
        (*f).reservation_at++;
    }
    print_resv(f);
};

void print_menu(flags *f){
    int c = (*f).selecting_course;
    int p = (*f).selecting_process;
    char s1[] = "Course Sel:   ";
    char s2[] = "Progress Sel:     ";
    char s3[] = "              ";
    locate(0,1);
    write_str(s1);
    locate(0,2);
    write_str(s2);
    locate(0,3);
    write_str(s3);
//    disp_number((*f).selecting_process,6,0);
    char cs[3];
    char ps[5];
    locate(COURSEX,COURSEY);
    switch(c){
        case NOMAL:
            strcpy(cs,"Nor");
            break;
        case SPPEDY:
            strcpy(cs,"Hig");
            break;
        case STRONG:
            strcpy(cs,"Car");
            break;
            
    }
    write_str(cs);

    locate(PROCESSX,PROCESSY);
    switch(p){
        case WRS:
            strcpy(ps,"W>R>S");
            break;
        case RS:
            strcpy(ps,"R>S");
            break;
        case R:
            strcpy(ps,"R");
            break;
        case S:
            strcpy(ps,"S");
            break;
        default:
            strcpy(ps,"err");
    }
    write_str(ps);
}

void print_resv(flags *f){
    print_menu(f);
    char s3[] = "Reserve:  H";
    locate(0,3);
    write_str(s3);
    locate(RESVX,RESVY);
    char h = '0' + (*f).reservation_at;
    write_char(h);
}