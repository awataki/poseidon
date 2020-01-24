#include "../Model/HardWareState.h"
#include "../Model/Flags.h"

#ifndef MENU_H
#define MENU_H

void update_menu_hardware_status(hard_ware_states *hw);
void next_menu(flags *f);
void next_process(flags *f);
void reservation_wash(flags *f);
void print_menu(flags *f);
void print_resv(flags *f);

#endif