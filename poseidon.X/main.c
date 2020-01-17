/* 
 * File:   main.c
 * Author: awataki
 *
 * Created on 17 January 2020, 11:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic.h>

/* CONFIGRATION */
__CONFIG(FOSC_INTRC_NOCLKOUT & WDTE_OFF & PWRTE_OFF & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF & LVP_OFF);
__CONFIG(WRT_OFF & BOR4V_BOR40V);

int main(int argc, char** argv) {
    return 0;
}

