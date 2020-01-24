#include "wash.h"
#include "../Domain/PracticeBox.h"
#include "../Domain/lcd_disp.h"

int ctoi(char c);

void update_wash_hardware_status(hard_ware_states *hw){
    (*hw).WATER_SENSOR = ctoi(read_Box_Sensor(1));
    (*hw).LAUNDRY_SENSOR = ctoi(read_Box_Sensor(2));
};

void start_wash(hard_ware_states *hw,flags *f){
    (*f).is_washing = 1;
    // move tub
    move_Box_Motor(1,1);
    (*hw).TUB = 1;
    // move wind
    move_Box_Motor(2,1);
    (*hw).WIND = 1;
    (*f).total_time = (*f).progress_time[0] + (*f).progress_time[1] + (*f).progress_time[2]; 
    char s[] = "Now Wash        ";
    char s2[] = "Remain Time:  min ";
    locate(0,1);
    write_str(s);
    locate(0,2);
    write_str(s2);
    return;
};

void stop_wash(hard_ware_states *hw,flags *f){
    (*f).is_washing = 0;
    move_Box_Motor(1,0);
    (*hw).TUB = 1;
    move_Box_Motor(2,0);
    (*hw).WIND = 1;
};



int ctoi(char c){
    if(c == '1'){
        return 1;
    }else{
        return 0;
    }
}