typedef enum {
	water, //水の有無
	laundry //洗濯物の有無
}Sensor;

// センサー用関数
int sensor_state(Sensor s){} // 対応するセンサーの値を返す。真なら1 偽なら0

// Usage
Sensor sen;
sen = water;
sensor_state(sen); //水が入っているかが取れる