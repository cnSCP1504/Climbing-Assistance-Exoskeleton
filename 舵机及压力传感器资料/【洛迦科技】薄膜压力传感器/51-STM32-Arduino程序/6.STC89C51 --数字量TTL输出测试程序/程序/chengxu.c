/********************************************************************
                            洛迦科技
实现功能:此版配套测试程序
使用芯片：STC89C52
晶振：11.0592MHZ
波特率：9600
编译环境：Keil
洛迦科技：runeskee.taobao.com

【声明】此程序仅用于学习与参考，引用请注明版权和作者信息！     
*********************************************************************/
/********************************************************************
说明：1、	当测量浓度大于设定浓度时，单片机IO口输出低电平
*********************************************************************/
#include<reg52.h>  	       //库文件
#define uchar unsigned char//宏定义无符号字符型
#define uint unsigned int  //宏定义无符号整型

/********************************************************************
                            I/O定义
*********************************************************************/
sbit LED=P2^7;	 //定义单片机P2口的第8位 （即P2.7）为指示端
sbit DOUT=P1^7;	 //定义单片机P1口的第8位 （即P1.7）为传感器的输入端

/********************************************************************
                            主函数
*********************************************************************/
void main()
{
	while(1)   //无限循环
	{
	 LED=1;	   //熄灭 灯
	 if(DOUT==0)//当浓度高于设定值时 ，执行条件函数
	 {

		if(DOUT==0)//确定 浓度高于设定值时 ，执行条件函数
	    {
		 LED=0;	   //点亮 灯
		}
	 }
	}
}	
/********************************************************************
                              结束
*********************************************************************/