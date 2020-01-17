/*--------------------------------------*/
/*  LCD Display subroutine Header file  */
/*                                      */
/*  program by T.kimura     2012/08/13  */
/*--------------------------------------*/
/*
 * File:   lcd_disp.h
 * Author:
 *
 * Created on 2012/08/17, 18:45
 */

#ifndef LCD_DISP_H
#define LCD_DISP_H

#ifdef  __cplusplus
extern "C" {
#endif

#if 0
/* PIC Configration set */
__CONFIG(FOSC_INTRC_NOCLKOUT & WDTE_OFF & PWRTE_OFF & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF & LVP_OFF);
__CONFIG(WRT_OFF & BOR4V_BOR40V);
#endif

/* LCD subroutine */
void    init_lcd( void );
void    disp_number( int, int, int);
void    write_lcd(int code, int rs);
void    write_lcd8(int code );
void    locate(int x, int y);
void    write_char(char c);
void    write_str(const char *s);
void    wait(int times);


#ifdef  __cplusplus
}
#endif

#endif  /* LCD_DISP_H */

