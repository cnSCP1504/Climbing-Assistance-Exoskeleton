#include<stc12c5a.h>
#include <intrins.h> 
#define uint unsigned int
#define uchar unsigned char
sbit P2_5 = P2^5;
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P0_7  = P0^7;
sbit S1 = P3^3;
sbit S2 = P3^4;
sbit S3 = P3^5;
void display(uint s);
void delay(uint z);
void beep();
void init ();
static void time_();
void keyscan();
void Read_init (uchar CHA);
unsigned int ADC_Read (void);
code char seven_seg[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
uint s,a,S1num;
int high,low;
uchar flag;
void main ()
{            
  	init ();
	time_();
    Read_init(0);
	while(1)
	{
	a = ADC_Read();
 	s =a/0.2048;		
	if(s>high&&flag== 0)
	{
		beep();
	}
	if(s<low&&flag == 0)
	{
		beep();
	}
	}

}  
void Read_init (uchar CHA)
{
 uchar AD_FIN=0; 
    CHA &= 0x07;  
    ADC_CONTR = 0x10;  
    _nop_();
    ADC_CONTR |= CHA; 
    _nop_();
    ADC_CONTR |= 0x80;  
     delay(1);  
}
unsigned int ADC_Read (void)
{
 unsigned char AD_FIN=0; 
    ADC_CONTR |= 0x08;  
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    while (AD_FIN ==0){  
        AD_FIN = (ADC_CONTR & 0x10);
    }
    ADC_CONTR &= 0xE7;       
return (ADC_RES*4);
}
void init ()
{
P2 = 0xf0;
P2M0 = 0x0F; 
P2M1 = 0x00;
P1M1 = 0x01;
}
void delay(uint z)
{
	uint i,j;
	for(i=0;i<z;i++)
	for(j=0;j<100;j++);
}
void beep()
{
	P2_5 = 0;
	delay(100);
	P2_5 = 1;
	delay(100);
}
void keyscan()
{
	if(S1==0)
	{
	delay(5);
	if(S1==0)
	{
	while(!S1);
	S1num++;
	if(S1num==1)
	{
	flag = 1;
	}
	if(S1num==2)
	{
	flag = 2;
	}
	if(S1num==3)
	{
	S1num = 0;
	flag = 0;
	}	
	}
	}
	if(S1num==1)
	{
	flag = 1;
	if(S2==0)
	{
	 delay(5);
	 if(S2==0)
	 {
	 while(!S2);
	 low+=100;
	 if(low>=5000)
	 {
	 low = 0;
	 }
	  }
	}
	if(S3==0)
	{
	 delay(5);
	 if(S3==0)
	 {
	 while(!S3);
	 low-=100;
	 if(low<=0)
	 {
	 low = 5000;
	 }
	  }
	}
	}
		if(S1num==2)
	{
	flag = 2;
	if(S2==0)
	{
	 delay(5);
	 if(S2==0)
	 {
	 while(!S2);
	 high+=100;
	 if(high>=5000)
	 {
	 high = 0;
	 }
	  }
	}
	if(S3==0)
	{
	 delay(5);
	 if(S3==0)
	 {
	 while(!S3);
	 high-=100;
	 if(high<=0)
	 {
	 high = 5000;
	 }
	  }
	}
	}
	
}
static void time_()
{
	TMOD = 0x02;
	TH0 = 0x00;
	TL0 = 0x00;
	ET0 = 1;
	TR0 = 1;
	EA = 1;
	flag = 0;
	high = 5000;
	low = 0;	
}
static void time0(void)interrupt 1
{
	unsigned char i; 
	keyscan();
	if(flag==0)
	{
	switch(i)
		{
		case 0:P0 = seven_seg[s/1000];P0_7  =0;P2_0 = 1;P2_1 =0;P2_2 = 0;P2_3 = 0;break;
		case 1:P0 = seven_seg[s%1000/100];P2_0 = 0;P2_1 =1;P2_2 = 0;P2_3 = 0;break;
		case 2:P0 = seven_seg[s%1000%100/10];P2_0 = 0;P2_1 =0;P2_2 = 1;P2_3 = 0;break;
		case 3:P0 = seven_seg[s%10];P2_0 = 0;P2_1 =0;P2_2 = 0;P2_3 = 1;break;
		}
		i++;
		if(i==4)i=0;
		}
	if(flag==1)
	{
	switch(i)
		{
		case 0:P0 = seven_seg[low/1000];P0_7  =0;P2_0 = 1;P2_1 =0;P2_2 = 0;P2_3 = 0;break;
		case 1:P0 = seven_seg[low%1000/100];P2_0 = 0;P2_1 =1;P2_2 = 0;P2_3 = 0;break;
		case 2:P0 = 0xff;P2_0 = 0;P2_1 =0;P2_2 = 1;P2_3 = 0;break;
		case 3:P0 = 0xc7;P2_0 = 0;P2_1 =0;P2_2 = 0;P2_3 = 1;break;
		}
		i++;
		if(i==4)i=0;
		}
	if(flag==2)
	{
	switch(i)
		{
		case 0:P0 = seven_seg[high/1000];P0_7  =0;P2_0 = 1;P2_1 =0;P2_2 = 0;P2_3 = 0;break;
		case 1:P0 = seven_seg[high%1000/100];P2_0 = 0;P2_1 =1;P2_2 = 0;P2_3 = 0;break;
		case 2:P0 = 0xff;P2_0 = 0;P2_1 =0;P2_2 = 1;P2_3 = 0;break;
		case 3:P0 = 0x89;P2_0 = 0;P2_1 =0;P2_2 = 0;P2_3 = 1;break;
		}
		i++;
		if(i==4)i=0;
		}			
}
