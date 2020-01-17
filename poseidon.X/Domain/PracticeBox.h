/*--------------------------------------*/
/*  Practice Box subroutine Header file */
/*                                      */
/*  program by T.kimura     2014/10/23  */
/*--------------------------------------*/
/*
 * File:   PracticeBox.h
 * Author:
 *
 * Created on 2014/10/23, 16:54
 */

#ifndef PRACTICEBOX_H
#define PRACTICEBOX_H

#ifdef  __cplusplus
extern "C" {
#endif

#if 0
/* PIC Configration set */
__CONFIG(FOSC_INTRC_NOCLKOUT & WDTE_OFF & PWRTE_OFF & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF & LVP_OFF);
__CONFIG(WRT_OFF & BOR4V_BOR40V);
#endif

/* Practice Box subroutine */
void practice_Box_init( void );
void move_Box_Motor( int no, int move );
void light_Box_LED( int no, int light );
char read_Box_SW( int no );
char read_Box_Sensor( int no );

#ifdef  __cplusplus
}
#endif

#endif  /*PRACTICEBOX_H */

