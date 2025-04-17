/******************************************************************************
----------------本例程仅供学习使用，未经作者允许，不得用于其他用途。-----------
---------------------------------------------*/
#include "main.h"
#include "LCD1602.h"



//定义变量
unsigned char KEY_NUM = 0;   
int count = 0;
int state = 0;
	

//****************************************************
//主函数
//****************************************************
void main()
{
	Init_LCD1602();
	LCD1602_write_com(0x80);
	LCD1602_write_word("welcome to use!");
	while(1)
	{
    	scanSensor();
		if(KEY_NUM == 1)
		{
			KEY_NUM = 0;
			LCD1602_write_com(0x80+0x40);
			LCD1602_write_word("count =");
			LCD1602_write_data(count%10000/1000+0x30);
			LCD1602_write_data(count%1000/100+0x30);
			LCD1602_write_data(count%100/10+0x30);
			LCD1602_write_data(count%10+0x30);

			count++;
			
			if(state == 2)
			  state = 0;
		}

	}
}

void scanSensor()
{
//	SENSOR = 1;
	if(SENSOR == 0)
	{
		Delay_ms(10);
		if(SENSOR == 0) 
		{
		  while(SENSOR == 0);
		  KEY_NUM = 1;
		} 
	}
}


//****************************************************
//MS延时函数
//****************************************************
void Delay_ms(unsigned int n)
{
	unsigned int  i,j;
	for(i=0;i<n;i++)
		for(j=0;j<123;j++);
}

