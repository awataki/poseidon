#include "../Model/HardWareState.h"
#include "../Model/Flags.h"

#ifndef WASH_H
#define WASH_H

void update_wash_hardware_status(hard_ware_states *hw);
void start_wash(hard_ware_states *hw,flags *f);
void stop_wash(hard_ware_states *hw,flags *f);

#endif