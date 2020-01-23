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
    (*f).wash_time = 0;
    (*f).rinse_time = 0;
    (*f).rinse_count = 0;
    (*f).spin_time = 0;
    (*f).is_washing = 0;
    (*f).reservation_at = 0;
    (*f).progress_time[0] = 0;
    (*f).progress_time[1] = 0;
    (*f).progress_time[2] = 0;
    (*f).in_progress = 0;
    (*f).total_time = 0;
}