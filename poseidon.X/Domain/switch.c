/* 
 * File:   switch.c
 * Author: awataki
 *
 * Created on 19 January 2020, 18:52
 */

#include <pic.h>
#include "switch.h"
#include "../Model/Switch.h"

int get_switch_state(int no){
    switch(no){
        case POWER:
            if((PORTB & 0x80) == '1'){
                return 1;
            }else{
                return 0;
            }
            break;
        case STOP:
            if((PORTB & 0x20) == '1'){
                return 1;
            }else{
                return 0;
            }
            break;
        case START:
            
            if((PORTB & 0x10) == '1'){
                return 1;
            }else{
                return 0;
            }
            break;
        case RESERVATION:
            if((PORTB & 0x08) == '1'){
                return 1;
            }else{
                return 0;
            }
            break;
        case PROCESS:
            if((PORTB & 0x04) == '1'){
                return 1;
            }else{
                return 0;
            }
            break;
        case COURSE:
            
            if((PORTB & 0x02) == '1'){
                return 1;
            }else{
                return 0;
            }
            break;
        default:
            return 0;
    }
};