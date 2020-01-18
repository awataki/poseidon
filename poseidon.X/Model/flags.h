#ifndef FLAGS_H
#define FLAGS_H
typedef struct {
  int POWER_SW;       // ON 1 OFF 0
  int START_SW;       // ON 1 OFF 0
  int STOP_SW;        // ON 1 OFF 0
  int MENU_SW;        // ON 1 OFF 0
  int PROCCESS_SW;    // ON 1 OFF 0
  int RESERVATION_SW; // ON 1 OFF 0
  int TUB_STATE;      // 洗濯槽 moving 1 stop 0
  int WIND_STATE;     // 回転羽 moving 1 stop 0
  int SENSOR_STATE;   //センサー
  int SENSOR2_STATE;  //センサー
  int _AT; // 洗い
// すすぎ
// 脱水
} _flags;
#endif