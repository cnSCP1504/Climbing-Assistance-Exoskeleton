/******************************************************************************
----------------本例程仅供学习使用，未经作者允许，不得用于其他用途。1.开发环境:Arduino IDE 1.0.6版本-------------------------------
----------------2.测试使用开发板型号：Arduino UNO R3---------------------------
----------------3.单片机使用晶振：16M------------------------------------------
-------------------------------------------------------------*/
#define SENSOR 2
int KEY_NUM = 0;
int count = 0;
int state = 0;

void setup() 
{ 
  pinMode(SENSOR,INPUT);
  Serial.begin(9600); // setup serial 
}

void loop() 
{ 
  scanSensor();
  if(KEY_NUM == 1)
  {
    KEY_NUM = 0;
  	Serial.println("press!");
  	Serial.print("count =");
  	Serial.println(count);
  	count++;

    
    if(state == 2)
      state = 0;
  }
  
}

void scanSensor()
{
  if(digitalRead(SENSOR) == LOW)
  {
    delay(10);
    if(digitalRead(SENSOR) == LOW) 
    {
      while(digitalRead(SENSOR) == LOW);
      KEY_NUM = 1;
    } 
  }
}



