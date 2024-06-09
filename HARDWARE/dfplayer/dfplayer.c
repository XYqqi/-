#include "dfplayer.h"
#include "delay.h"


/*************************************************************************************************
*	函 数 名:	DFPLayer_GPIO_Config
*
*	返 回 值:	无
*
*	函数功能:	usart2 IO口初始化
*	
*************************************************************************************************/
static void DFPLayer_GPIO_Config	(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd ( USART2_TX_CLK|USART2_RX_CLK, ENABLE);//IO口时钟配置

	//IO配置
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//复用模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;//速度等级

	//初始化 TX	引脚
	GPIO_InitStructure.GPIO_Pin = USART2_TX_PIN;	 
	GPIO_Init(USART2_TX_PORT, &GPIO_InitStructure);	
	//初始化 RX 引脚													   
	GPIO_InitStructure.GPIO_Pin = USART2_RX_PIN;	
	GPIO_Init(USART2_RX_PORT, &GPIO_InitStructure);		
	
	//IO复用，复用到USART2
	GPIO_PinAFConfig(USART2_TX_PORT,USART2_TX_PinSource,GPIO_AF_USART2); 
	GPIO_PinAFConfig(USART2_RX_PORT,USART2_RX_PinSource,GPIO_AF_USART2);	
}

/*************************************************************************************************
*	函 数 名:	DFPlayer_Usart_Config
*
*	返 回 值:	无
*
*	函数功能:	usart2初始化
*	
*************************************************************************************************/
void DFPlayer_Usart_Config(void)
{		
	USART_InitTypeDef USART_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	// IO口初始化
	DFPLayer_GPIO_Config();
		 
	// 配置串口各项参数
	USART_InitStructure.USART_BaudRate 	 = USART2_BaudRate; //波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位
	USART_InitStructure.USART_StopBits   = USART_StopBits_1; //停止位1位
	USART_InitStructure.USART_Parity     = USART_Parity_No ; //无校验
	USART_InitStructure.USART_Mode 	    = USART_Mode_Rx | USART_Mode_Tx; //发送和接收模式
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 不使用硬件流控制
	
	USART_Init(USART2,&USART_InitStructure); //初始化串口1
	USART_Cmd(USART2,ENABLE);	//使能串口1
}

/*****************************************************************************************
*	函 数 名: USART_SendCmd
*	入口参数: cmd - 控制指令
*            Parameter1 - 查询的数据高字节(比如歌曲序号)
*            Parameter2 - 查询的数据低字节
*            checksum - 累加和校验[不计起始位$] 
*	返 回 值: 无
*	函数功能: 通过串口向DFPlayer模块发送控制指令
*	说    明: 无
******************************************************************************************/
void USART_SendCmd(uint8_t cmd, uint8_t Parameter1, uint8_t Parameter2, uint8_t checksum)
{
    uint16_t Checksum = Version + Cmd_Len + cmd + Feedback + Parameter1 + Parameter2;
    Checksum = 0-Checksum;

    uint8_t CmdSequence[10] = { Start_Byte, Version, Cmd_Len, cmd, Feedback, Parameter1, Parameter2, (Checksum>>8)&0x00ff, (Checksum&0x00ff), End_Byte};

    send_cmd_sequence(USART_UX, CmdSequence, 10);
}

//串口2发送一个字节
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
    /* 发送一个字节数据到USART */
    USART_SendData(pUSARTx,ch);

    /* 等待发送数据寄存器为空 */
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

//串口2发送指令
void send_cmd_sequence(USART_TypeDef * pUSARTx, uint8_t * pData, uint8_t Size)
{
    uint8_t i;
    for(i=0; i<Size; i++)
    {
        Usart_SendByte( pUSARTx, pData[i]);
    }
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

//播放音乐
void DF_Playfolder (void)
{
    USART_SendCmd(0x0D,0x00,0x01, 0xED);
    Delay_ms(200);
}

//音乐暂停
void DF_Pause (void)
{
    USART_SendCmd(0x0E,0x00,0x00,0xED);
    Delay_ms(200);
}

//上一首
void DF_Previous (void)
{
    USART_SendCmd(0x02,0x00,0x01,0xF8);
    Delay_ms(200);
}

//下一首
void DF_Next (void)
{
    USART_SendCmd(0x01, 0x00, 0x01, 0xF9);
    Delay_ms(200);
}

//音量增加
void DF_Increase_Volume (void)
{
    USART_SendCmd(0x04, 0x00, 0x00, 0xF7);
    Delay_ms(200);
}

//音量减小
void DF_Decrease_Volume (void)
{
    USART_SendCmd(0x05, 0x00, 0x00, 0xF6);
    Delay_ms(200);
}


