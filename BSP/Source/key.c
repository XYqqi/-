#include "key.h" 

/* ��ʼ���������ţ�����Ϊ�������롢�ٶȵȼ�2M */

/*************************************************************************************************
*	�� �� ��:	KEY_Init
*
*	��������:	����IO�ڳ�ʼ��
*************************************************************************************************/
void KEY_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
	RCC_AHB1PeriphClockCmd ( KEY_CLK, ENABLE);//��ʼ��KEYʱ��	
	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;//���ģʽ
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;//�ٶ�ѡ��
	GPIO_InitStructure.GPIO_Pin   = KEY_PIN;	 
	
	GPIO_Init(KEY_PORT, &GPIO_InitStructure);	
}

/*************************************************************************************************
*	�� �� ��:	KEY_Scan
*
*	�� �� ֵ:	KEY_ON - �������£�KEY_OFF - �����ſ�
*
*	��������:	����ɨ��
*	
*************************************************************************************************/
uint8_t	KEY_Scan(void)
{
	if( GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0 )//��ⰴ���Ƿ񱻰���
	{	
		Delay_ms(10);//��ʱ����
		if(GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0)//�ٴμ���Ƿ�Ϊ�͵�ƽ
		{
			while(GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0);//�ȴ������ſ�
			return KEY_ON;//���ذ������±�־
		}
	}
	return KEY_OFF;	
}