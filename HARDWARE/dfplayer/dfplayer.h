#ifndef __DFPLAYER_H_
#define __DFPLAYER_H_

#include "stm32f4xx.h"

#define Start_Byte                  0x7E
#define End_Byte                    0xEF
#define Version                     0xFF
#define Cmd_Len                     0x06
#define Feedback                    0x00              //If need for Feedback: 0x01,  No Feedback: 0

/*----------------------USART配置宏 ------------------------*/
#define  USART2_BaudRate  9600
#define  USART_UX         USART2

#define  USART2_TX_PIN				GPIO_Pin_2// TX 引脚
#define	 USART2_TX_PORT				GPIOA// TX 引脚端口
#define	 USART2_TX_CLK				RCC_AHB1Periph_GPIOA// TX 引脚时钟
#define  USART2_TX_PinSource        GPIO_PinSource2// 引脚源

#define  USART2_RX_PIN				GPIO_Pin_3// RX 引脚
#define	 USART2_RX_PORT				GPIOA// RX 引脚端口
#define	 USART2_RX_CLK				RCC_AHB1Periph_GPIOA// RX 引脚时钟
#define  USART2_RX_PinSource        GPIO_PinSource3// 引脚源

/********************************函数声明*********************************************************/
void DFPLayer_GPIO_Config(void);//USART2引脚初始化
void DFPlayer_Usart_Config(void);//USART2串口初始化
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);//串口发送一个字节
void send_cmd_sequence(USART_TypeDef * pUSARTx, uint8_t * pData, uint8_t Size);//串口发送指令
void USART_SendCmd(uint8_t cmd, uint8_t Parameter1, uint8_t Parameter2, uint8_t checksum);
void DF_Playfolder (void);//播放音乐
void DF_Pause (void);//音乐暂停
void DF_Previous (void);//上一首
void DF_Next (void);//下一首
void DF_Increase_Volume (void);//音量增加
void DF_Decrease_Volume (void);//音量减小

#endif /* __DFPLAYER_H_ */