// #define SENSOR 26
int KEY_NUM = 0;
int count = 0;
int state = 0;

void setup() { 
  // Serial.println('NOW SETUP');
  // pinMode(SENSOR, INPUT);
  Serial.begin(115200); // 初始化串口
  while (!Serial){}
}

void loop() { 
  Serial.println(10000); 
  // scanSensor();
  // if (KEY_NUM == 1) {
  //   KEY_NUM = 0;
  //   Serial.println("press!");
  //   Serial.print("count =");
  //   Serial.println(count);
  //   count++;

  //   if (state == 2)
  //     state = 0;
  // }  
}

// void scanSensor() {
//   if (digitalRead(SENSOR) == LOW) {
//     delay(10); // 消抖延时
//     if (digitalRead(SENSOR) == LOW) { // 二次检测确认按键按下
//       while (digitalRead(SENSOR) == LOW); // 等待按键释放
//       KEY_NUM = 1; // 标记按键事件
//     } 
//   }
// }
    