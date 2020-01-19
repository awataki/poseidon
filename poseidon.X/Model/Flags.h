/* 
 * File:   Flags.h
 * Author: awataki
 *
 * Created on 19 January 2020, 20:17
 */

#include "Course.h"

#ifndef FLAGS_H
#define	FLAGS_H

typedef struct{
    int selecting_course;
    int selecting_process;
    int wash_time;
    int rinse_time;
    int rinse_count;
    int spin_time;
    int power;
    int is_washing;
    int reservation_at;
    int progress_time[3];
    int in_progress;
    int total_time;
}flags;

void init_flag(flags *f);

#endif	/* FLAGS_H */

