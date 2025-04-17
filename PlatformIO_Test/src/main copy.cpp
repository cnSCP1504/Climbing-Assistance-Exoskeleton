#include <cstdint>
#include <cstddef>
#include <Arduino.h>

#include <STSCTRL.h>
#include <SMS_STS.h>

SMS_STS st;
int TEST_ID = 1;  // 要测试的舵机ID

#define PRESSURE_SENSOR_DO_PIN 26
// #define PRESSURE_SENSOR_AO_PIN 5 开发板上没有模拟信号引脚
// const float PRESSURE_SENSOR_THRESHOLD;

void serial_connection_test(){};

void pressure_sensor_DO_test(
  uint8_t pressure_sensor_pin
)
{
  uint8_t status = digitalRead(pressure_sensor_pin);
  if (status == 1)
  {
    Serial.printf("Pressure sensor value: high (%d)\n", status);
  }
  else
  {
    Serial.printf("Pressure sensor value: low (%d)\n", status);
  }
};

void servo_test(
  SMS_STS *st,
  int servo_id
)
{
  int ID = st->Ping(servo_id);  //ping该ID的舵机，ping不通返回-1
  if(ID!=-1)
  {
    Serial.print("Servo ID:");
    Serial.println(ID, DEC);
    delay(100);
  }
  else
  {
    Serial.println("Ping servo ID error!");
    delay(2000);
  }
};


/*
setup
*/
void setup() 
{
  Serial.begin(115200);
  while(!Serial) {}
  servoInit();
}
void loop() 
{
  Serial.printf("hello world\n");
  delay(1000);
}
