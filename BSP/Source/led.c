#include "led.h"  

/*************************************************************************************************
*	�� �� ��:	LED_Init
*
*	��������:	IO�ڳ�ʼ��
*	 
*************************************************************************************************/

void LED_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
	RCC_AHB1PeriphClockCmd ( LED1_CLK, ENABLE); 	//��ʼ��GPIOGʱ��	
	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   //���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  //�������
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;	//����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; //�ٶ�ѡ��
	
	//��ʼ�� LED1 ����
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;	 
	GPIO_Init(LED1_PORT, &GPIO_InitStructure);	
	
	GPIO_ResetBits(LED1_PORT,LED1_PIN);  //PG7����͵�ƽ
}




