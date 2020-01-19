/*--------------------------------------*/
/*  LCD Display Subroutine for PIC      */
/*                                      */
/*  program by T.kimura     2012/08/13  */
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
#include "lcd_disp.h"

#define     wtime   100

/*************************/
/* LCD Initilize Routine */
/*************************/
void init_lcd()
{
    /* Analog port Disable */
    ANSEL  = 0x03;          /* AN2-7 disable (RA0-5, RE0-2) , AN0,1 Enable */
    ADCON0 = 0x00;          /* ADC disable */
    CM1CON0 = 0x00;         /* Comparator1 is disable */
    CM2CON0 = 0x00;         /* Comparator2 is disable */
    PCON = 0x00;            /* Power Control is disable */
    SSPCON = 0x00;          /* Sirial port is disable */

    /* Port RA Setting */
    PORTA = 0x00;           /* Initial value */
    TRISA = 0x03;           /* RA2-5 set to output, RA0,1 set to Input */

    /* Port RE Setting */
    TRISE = 0x00;           /* RE set to output */
    PORTE = 0x00;           /* Initial value */


    /* LCD Initilize */
    wait(100);
    write_lcd8(0x3);        /* LCD Function set 1 */
    wait(100);
    write_lcd8(0x3);        /* LCD Function set 2 */
    write_lcd8(0x3);        /* LCD Function set 3 */
    write_lcd8(0x2);        /* Function set */
    write_lcd(0x28, 0);     /* Function set */
    write_lcd(0x0c, 0);     /* Display ON && ???? OFF*/
//    write_lcd(0x0e, 0);     /* Display ON && ???? ON */
    write_lcd(0x06, 0);     /* Entery mode */
    write_lcd(0x01, 0);     /* Display CLS */

}

/*----------------------------------------*/
/* Display 1 Digit Number                 */
/*----------------------------------------*/
void disp_number( int number, int x, int y )
{
    char    num;

    /* Check Number */
    if( number < 0 && number > 9 ) {
        number = 0;
    }

    num = (char)number + 0x30;    /* Set Ascii code */

    locate( x, y );
    write_lcd( num, 1 );    /* Display number */
}


/*--------------------------*/
/* Write 8bit data to LCD   */
/*--------------------------*/
void    write_lcd(int code, int rs)
{

    RE2 = 1;                   /* Enable bit is High */
/* UPper 4bit */
    PORTA = ((unsigned char)code>>2) & 0x3C;  /* D4-D7 ? RA2-5??? */
    if(rs) {
        RE1 = 1;             /* RS is High */
    }
    else {
        RE1 = 0;             /* RS is Low */
    }
    wait(wtime);
    RE2 = 0;                /* Enable bit is Low */
    wait(wtime);

/* Under 4bit */
    RE2 = 1;                /* Enable bit is Low */
    PORTA = ((unsigned char)code<<2) & 0x3C;  /* D4-D7 ? RA2-5??? */

    if(rs) {
        RE1 = 1;            /* RS is High */
    }
    else {
        RE1 =0;             /* RS is Low */
    }
    wait(wtime);
    RE2 = 0;                /* Enable bit is Low */
    wait(wtime);
}

/*------------------------*/
/* Write 4bit data to LCD */
/*------------------------*/
void    write_lcd8(int code )
{
    RE2 = 1;        /* Enable bit is High */
    PORTA = ((unsigned char)code<<2) & 0x3C;  /* D4-D7 ? RA2-5??? */
    wait(wtime);
    RE2 = 0;        /* Enable bit is Low */
    wait(wtime);
}


/*--------------------------*/
/* Set Corser location      */
/*--------------------------*/
void    locate(int x, int y)
{
    unsigned char col = 0x40;
    if( y==2 )
    {
        col = 0x14;
        y = 1;
    }
    else if( y==3 )
    {
        col = 0x54;
        y = 1;
    }

    write_lcd(0x80+x+y*col, 0);
 }

/*------------------*/
/* Display 1 Char   */
/*------------------*/
void    write_char(char c)
{
    write_lcd(c, 1);
}

/*--------------------*/
/* Display String     */
/*--------------------*/
void    write_str(const char *s)
{
    while(*s)
    {
        write_lcd(*s, 1);
        s++;
    }
}

/*----------*/
/* Wait     */
/*----------*/
void    wait(int times)
{
    int i, j;

    if(times<=0)
        return;

    for( i=0, j=0 ; i<times ; i++ )
    {
        j++;
    }
}


