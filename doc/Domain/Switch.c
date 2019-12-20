typedef enum {
	power, //電源ボタン
	start, //開始ボタン
	stop, //停止ボタン
	course_select, //洗濯コース設定ボタン
	proccess_select //行程コース設定ボタン
}Switch;

// SW用関数
int is_pushed(Switch s){} //  対応するスイッチが押されているかを返す。 真なら1 偽なら0

// Usage
Switch sw;
sw = power;
is_pushed(s); // 電源ボタンの値が取れる
sw = stop;
is_pushed(s); // 停止ボタンの値が取れる
