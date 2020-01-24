/* 
 * File:   Flags.c
 * Author: awataki
 *
 * Created on 24 January 2020, 03:44
 */

#include "Flags.h"

void init_flag(flags *f){
    (*f).selecting_course = 0;
    (*f).selecting_process = 0;
    (*f).wash_time = 10;
    (*f).rinse_time = 5;
    (*f).rinse_count = 2;
    (*f).spin_time = 10;
    (*f).is_washing = 0;
    (*f).reservation_at = 0;
    (*f).progress_time[0] = 10;
    (*f).progress_time[1] = 10;
    (*f).progress_time[2] = 10;
    (*f).in_progress = 0;
    (*f).total_time = 10;
}