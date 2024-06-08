#include "rtc.h"

RTC_TimeTypeDef TimeSet_Struct;	 // ʱ����Ϣ

/***************************************************************************************************
*	�� �� ��:	RTC_Initialize
*	��ڲ���:	��
*	�� �� ֵ:	��
*	��������:	��ʼ��RTC
*	˵    ��:   ��һ�γ�ʼ��RTCʱ����������д������0XAAAA��֮���Դ��ж��Ƿ���Ҫ���³�ʼ��RTC
***************************************************************************************************/
void RTC_Initialize(void)
{
	RTC_InitTypeDef RTC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	PWR_BackupAccessCmd(ENABLE);		

	if(RTC_ReadBackupRegister(RTC_BKP_DR0)!=0xAAAA)/����Ƿ��һ������RTC
	{	
		RCC_LSEConfig(RCC_LSE_ON);//����LSEʱ�ӣ�����ӵ�32.768K����
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET);//�ȴ�ʱ���������
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);//����RTCʱ��ΪLSEʱ��
		
		RTC_InitStructure.RTC_AsynchPrediv = 0x7F;//�첽��Ƶϵ���������ֲ���Ƽ�������Ϊ���
		RTC_InitStructure.RTC_SynchPrediv  = 0xFF;//ͬ����Ƶϵ��
		RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;//ʱ���ʽΪ24Сʱ��
		RTC_Init(&RTC_InitStructure);		
		RCC_RTCCLKCmd(ENABLE);//ʹ��RTC	

		TimeSet_Struct.RTC_Hours = 0;TimeSet_Struct.RTC_Minutes = 0;TimeSet_Struct.RTC_Seconds = 0;// ��ʼʱ������Ϊ 00:00:00
		RTC_SetTime(RTC_Format_BIN,&TimeSet_Struct);
		RTC_WriteBackupRegister(RTC_BKP_DR0,0xAAAA);
	}	 	
}