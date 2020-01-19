/*--------------------------------------------------*/
/*  Sensor Subroutine for PIC                       */
/*                                                  */
/*  program by T.kimura             2012/08/23      */
/*--------------------------------------------------*/
/*  Debug return of check_Tempture  2014/10/30  TK  */
/*--------------------------------------------------*/

#include <pic.h>
#include "lcd_disp.h"
#include "sensor.h"

void sensor_init( void )
{
    /* Rotary Encoder initilize */
    CCP1CON = 0x00;     // PWM mode is disable

    /* Set Port D config */
    TRISD = 0xC0;       // bit 0-5 OUT, bit6-7 IN

    /* Tempture sensor initilize */
    ANSEL  = 0x03;          /* AN0,1 Enable, AN2-7 disable (RA0-5, RE0-2) */
    PORTA = 0x00;
    TRISA = 0x03;           /* RA2-5 set to output, RA0,1 set to Input */

    /* set Port A confit */
    ADCON1 = 0x80;          /* ADFM:Left just fit, Vdd & Vss as Vref */

}
/*-------------------*/
/* Timer0 Initilaize */
/*-------------------*/
void timer0_init( void )
{
    TMR0 = 0;           /* Timer0 Module Reg. */
    OPTION_REG = 0x87;  /* Pull-up Disable, PreScall:256 */
 }

/*------------------------*/
/* Rotary Encoder         */
/* return 0: not move     */
/*        1: CW move      */
/*        2: CCW mode     */
/*------------------------*/
char check_Rotary( void )
{
    static char bef_rot_dat = 0x00;
    char now_rot_dat;
    char rot_dir = 0x00;

    now_rot_dat = PORTD & 0xC0; /* bit 7,6 is eblable */
    if( now_rot_dat != 0x00 )
    {
        if( bef_rot_dat != now_rot_dat  )
        {
            rot_dir = (bef_rot_dat << 1) + now_rot_dat;
            bef_rot_dat = now_rot_dat;

            if ( (rot_dir & 0x80) && (now_rot_dat==0x80) )
            {
                rot_dir = CCW;
            }
            else if( !(rot_dir & 0x80) && (now_rot_dat==0x40) )
            {
                rot_dir = CW;
            }
        }
    }
    else
    {
        bef_rot_dat = 0x00;
        rot_dir = 0x00;
    }

    return rot_dir;
}

short check_Tempture( void )
{
    short temp1, temp2;

    /*-----*/
    /* AN0 */
    /*-----*/
    ADCON0 = 0xC1;              /* ADC Frc Clock & AD0 Enable */
    wait(100);
    ADCON0bits.GO_DONE = 1;     /* Start conversion */
    while(ADCON0bits.GO_DONE);
    temp1 = (short)ADRESL+(short)((ADRESH&0x03)<<8);

    /*-----*/
    /* AN1 */
    /*-----*/
    ADCON0 = 0xC5;              /* ADC Frc Clock & AD1 Enable */
    wait(100);
    ADCON0bits.GO_DONE = 1;     /* Start conversion */
    while(ADCON0bits.GO_DONE);
    temp2 = (short)ADRESL+(short)((ADRESH&0x03)<<8);

    return ((temp1-temp2)/2);   /* ((5V*Value)/1024bit)*100deg */
}
