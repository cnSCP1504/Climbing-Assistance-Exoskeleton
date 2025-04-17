#include <Arduino.h>
#define DEBUGSerial Serial
int sensorPin = A0;
#define PRESS_MIN 20
#define PRESS_MAX 6000
#define VOLTAGE_MIN 0
#define VOLTAGE_MAX 5000


  


void setup() {
  DEBUGSerial.begin(9600);
  Serial.println("setup end!"); 
  // put your setup code here, to run once:

}

void loop() {
	long Fdata = getPressValue(sensorPin);
	DEBUGSerial.print("F = ");
	DEBUGSerial.print(Fdata);
	DEBUGSerial.println(" g,");
	delay(300);
  // put your main code here, to run repeatedly:

}
long getPressValue(int pin)
{
	long PRESS_AO = 0;
	int VOLTAGE_AO = 0;
	int value = analogRead(pin);
  int reversedValue = 1023 - value;


	DEBUGSerial.print("AD = ");
	DEBUGSerial.print(reversedValue);
	DEBUGSerial.print(" ,");

	VOLTAGE_AO = map(value, 0, 1023, 5000, 0);


	DEBUGSerial.print("V = ");
	DEBUGSerial.print(VOLTAGE_AO);
	DEBUGSerial.print(" mv,");
  


	if(VOLTAGE_AO < VOLTAGE_MIN)
	{
		PRESS_AO = 0;
	}
	else if(VOLTAGE_AO > VOLTAGE_MAX)
	{
		PRESS_AO = PRESS_MAX;
	}
	else
	{
		PRESS_AO = map(VOLTAGE_AO, VOLTAGE_MIN, VOLTAGE_MAX, PRESS_MIN, PRESS_MAX);
	}
	

	return PRESS_AO;
}
