#include "wash.h"
#include "../Domain/PracticeBox.h"

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