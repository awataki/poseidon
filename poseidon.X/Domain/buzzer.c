/*--------------------------------------*/
/*  Sensor Subroutine for PIC           */
/*                                      */
/*  program by T.kimura     2012/08/23  */
/*--------------------------------------*/
/*  16 Char x 4 line                    */
/*                                      */
/*  Port setting                        */
/*      D7-D4 = Port RA2-5              */
/*      E     = Port RE2                */
/*      R/-W  = Port RE1                */
/*      RS    = Port RE0                */
/*--------------------------------------*/

#include <pic.h>
#include "buzzer.h"

void buzzer_init( void )
{
    char portc_dir;

    /* Set Port C */
    RCSTA = 0x00;       // Serial disable (RC7-6)
    SSPCON = 0x00;      // Serial disable (RC5-4)

    /* Port C setting */
    TRISC = TRISC & 0xFB;   // bit 2 is OUTPUT (Direction)
    PORTC = PORTC | 0xFB;   // bit 2 is LOW (Buzzer is no beep)
}

/*--------------------------*/
/* Buzzer Sound Function    */
/*  char sound              */
/*  0: Sound OFF            */
/*  1: Sound ON             */
/*--------------------------*/
void buzzer( char sound )
{
    if( sound )
    {
        PORTC = PORTC | 0x04;
    }
    else
    {
        PORTC = PORTC & 0xFB;
    }
}
