#include <LobotServoController.h>

#include <arduino.h>

#define pressure_DO_pin1 4
#define pressure_DO_pin2 5

LobotServoController myse;    //实例化舵机控制对象 

int get_pressure_DO_status(int pin){
  if (digitalRead(pin) == 1){
    delay(10);
    if (digitalRead(pin) == 1){
     return true;
    }
  }
  return false;
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  pinMode(pressure_DO_pin1, INPUT);
}

void loop() {
  static int status = 0;
  static int pre_status = 0;
  static int change_status = 0;
  
  // status 0 默认状态
  // status 1 放松状态
  // status 2 锁止状态
  
  // 左手压力高且右手压力低 -> 放松状态
  if (get_pressure_DO_status(pressure_DO_pin1) == 1 && get_pressure_DO_status(pressure_DO_pin2) == 0 && pre_status !=1) {
    status = 1;
    change_status = 1;
  }
  
  // 左手压力低且右手压力高 -> 锁止状态
  if (get_pressure_DO_status(pressure_DO_pin1) == 0 && get_pressure_DO_status(pressure_DO_pin2) == 1 && pre_status !=2) {
    status = 2;  // 修改：从status=0改为status=2
    change_status = 1;
  }
  
  if (change_status) {
    switch(status) {
      case 0:
        // 默认状态下的操作（如果有需要）
        break;
      case 1:
        myse.moveServo(1, 0, 200);  // 舵机移动到放松状态
        break;
      case 2:
        myse.moveServo(1, 300, 200);  // 舵机移动到锁止状态
        break;
      default:
        break;
    }
    change_status = 0;
  }
  
  pre_status = status;  // 新增：更新前一个状态
  
  delay(400);
}