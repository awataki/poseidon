/*--------------------------------------------------*/
/*  Practice Box Subroutine for PIC                 */
/*                                                  */
/*  program by T.kimura     2014/10/23              */
/*--------------------------------------------------*/
/*  delete sensor.h @ include part  2014/10/30  TK  */
/*--------------------------------------------------*/
/*  16 Char x 4 line                                */
/*                                                  */
/*  Port setting                                    */
/*      Motor#1 = Port RC6                          */
/*      Motor#2 = Port RC7                          */
/*      SW1     = Port RB0                          */
/*      SW2     = Port RC4 (Common)                 */
/*      Sensor1 = Port RC3                          */
/*      Sensor2 = Port RC4 (Common)                 */
/*      LED#1   = Port RD0                          */
/*      LED#2   = Port RD1                          */
/*      LED#3   = Port RD2                          */
/*      LED#4   = Port RD3                          */
/*--------------------------------------------------*/

#include <pic.h>
#include "lcd_disp.h"
/* #include "sensor.h" */

void practice_Box_init( void )
{
    /* Set Port B config */
    /* This port B was set by pic_init() */

    /* Set Port C config */
    /* Port C setting */
    TRISC = TRISC & 0x2F;   // bit 6,7 is OUTPUT (Direction)
    TRISC = TRISC | 0x18;   // bit 3,4 is INPUT (Direction)

    /* Set Port D config */
    /* This port D was set by pic_init() */

}

/*------------------------*/
/* Move Motor             */
/*                        */
/* no : motor no.         */
/*          1 or 2        */
/* move 0: stop           */
/*      1: move           */
/*------------------------*/
void move_Box_Motor( int no, int move )
{
    char data;

    data = PORTC;       /* read PORTC status */

    /* Motor#1 (bit 6) */
    if( no==1) {
        if( move==1) {
            PORTC = data | 0x40 ;   /* bit 6 is ON */
        }
        else {
            PORTC = data & 0xBF ;   /* bit 6 is OFF */
        }
    }
    /* Motor#1 (bit 7) */
    else if( no==2 )
    {
        if( move==1) {
            PORTC = data | 0x80 ;   /* bit 7 is ON */
        }
        else {
            PORTC = data & 0x7F ;   /* bit 7 is OFF */
        }
    }

    return;
}

/*------------------------*/
/* Light LED              */
/*                        */
/* no : LED no.           */
/*          1 - 4         */
/* light 0: OFF           */
/*       1: ON            */
/*------------------------*/
void light_Box_LED( int no, int light )
{
    char data;

    data = PORTD;       /* read PORTD status */

    /* LED#1 (bit 0) */
    if( no==1) {
        if( light==1) {
            PORTD = data | 0x01 ;   /* bit 0 is ON */
        }
        else {
            PORTD = data & 0xFE ;   /* bit 0 is OFF */
        }
    }
    /* LED#2 (bit 1) */
    else if( no==2 )
    {
        if( light==1) {
            PORTD = data | 0x02 ;   /* bit 1 is ON */
        }
        else {
            PORTD = data & 0xFD ;   /* bit 1 is OFF */
        }
    }
    /* LED#2 (bit 2) */
    else if( no==3 )
    {
        if( light==1) {
            PORTD = data | 0x04 ;   /* bit 2 is ON */
        }
        else {
            PORTD = data & 0xFB ;   /* bit 2 is OFF */
        }
    }
    /* LED#3 (bit 3) */
    else if( no==4 )
    {
        if( light==1) {
            PORTD = data | 0x08 ;   /* bit 3 is ON */
        }
        else {
            PORTD = data & 0xF7 ;   /* bit 4 is OFF */
        }
    }

    return;
}

/*------------------------*/
/* Read SW status         */
/*                        */
/* no : SW no.            */
/*          1(A) or 2(B)  */
/* retun 0: OFF           */
/*       1: ON            */
/*------------------------*/
char read_Box_SW( int no )
{
    char data;
    char status;

    /* SW-A (bit 4 @PORTC)*/
    if( no==1 ) {
        data = PORTC;       /* read PORTC status */
        if( data & 0x10 ) {
            status = 0;
        }
        else {
            status = 1;
        }
    }
    /* SW-B (bit 0 @PORTB)*/
    else if( no==2 ) {
        data = PORTB;       /* read PORTB status */
        if( data & 0x01 ) {
            status = 0;
        }
        else {
            status = 1;
        }
    }

    return status;
}

/*------------------------*/
/* Read Sensor status     */
/*                        */
/* no : Sensor no.        */
/*          1(A) or 2(B)  */
/*                        */
/* retun 0: Turn ON       */
/*       1: Cut OFF       */
/*------------------------*/
char read_Box_Sensor( int no )
{
    char data;
    char status;

    data = PORTC;       /* read PORTC status */

    /* Sensor-A (bit 4)*/
    if( no==1 ) {
        if( data & 0x10 ) {
            status = 1;
        }
        else {
            status = 0;
        }
    }
    /* Sensor-B (bit 3)*/
    else if( no==2 ) {
        if( data & 0x08 ) {
            status = 1;
        }
        else {
            status = 0;
        }
    }

    return status;
}

