#include "stm32f4xx.h"
#include "led.h"   
#include "delay.h"


int main(void)
{
	Delay_Init();		//延时函数初始化
	LED_Init();			//LED初始化

	while (1)
	{		
		LED1_ON;
		Delay_ms(1000);	
		LED1_OFF;
		Delay_ms(1000);	
	}	
}



