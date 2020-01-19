#ifndef HRAD_WARE_STATE_H
#define HRAD_WARE_STATE_H
typedef struct {
  int POWER_SW;       // ON 1 OFF 0
  int START_SW;       // ON 1 OFF 0
  int STOP_SW;        // ON 1 OFF 0
  int MENU_SW;        // ON 1 OFF 0
  int PROCCESS_SW;    // ON 1 OFF 0
  int RESERVATION_SW; // ON 1 OFF 0
  int TUB;      // 洗濯槽 moving 1 stop 0
  int WIND;     // 回転羽 moving 1 stop 0
  int WATER_SENSOR;   //水位センサー ok 1 ng 0
  int LAUNDRY_SENSOR;  //洗濯物センサー ok 1 ng 0
} hard_ware_states;
#endif