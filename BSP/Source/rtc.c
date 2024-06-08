#include "rtc.h"

RTC_TimeTypeDef TimeSet_Struct;	 // 时间信息

/***************************************************************************************************
*	函 数 名:	RTC_Initialize
*	入口参数:	无
*	返 回 值:	无
*	函数功能:	初始化RTC
*	说    明:   第一次初始化RTC时，往后备区域写入数据0XAAAA，之后以此判断是否需要重新初始化RTC
***************************************************************************************************/
void RTC_Initialize(void)
{
	RTC_InitTypeDef RTC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	PWR_BackupAccessCmd(ENABLE);		

	if(RTC_ReadBackupRegister(RTC_BKP_DR0)!=0xAAAA)/检测是否第一次配置RTC
	{	
		RCC_LSEConfig(RCC_LSE_ON);//启动LSE时钟，即外接的32.768K晶振
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET);//等待时钟配置完毕
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);//配置RTC时钟为LSE时钟
		
		RTC_InitStructure.RTC_AsynchPrediv = 0x7F;//异步分频系数，根据手册的推荐，设置为最大
		RTC_InitStructure.RTC_SynchPrediv  = 0xFF;//同步分频系数
		RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;//时间格式为24小时制
		RTC_Init(&RTC_InitStructure);		
		RCC_RTCCLKCmd(ENABLE);//使能RTC	

		TimeSet_Struct.RTC_Hours = 0;TimeSet_Struct.RTC_Minutes = 0;TimeSet_Struct.RTC_Seconds = 0;// 初始时间设置为 00:00:00
		RTC_SetTime(RTC_Format_BIN,&TimeSet_Struct);
		RTC_WriteBackupRegister(RTC_BKP_DR0,0xAAAA);
	}	 	
}