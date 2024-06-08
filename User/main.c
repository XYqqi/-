#include "stm32f4xx.h"
#include "led.h"   
#include "delay.h"


int main(void)
{
	Delay_Init();		//��ʱ������ʼ��
	LED_Init();			//LED��ʼ��

	while (1)
	{		
		LED1_ON;
		Delay_ms(1000);	
		LED1_OFF;
		Delay_ms(1000);	
	}	
}



