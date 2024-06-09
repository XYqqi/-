#ifndef __DFPLAYER_H_
#define __DFPLAYER_H_

#include "stm32f4xx.h"

#define Start_Byte                  0x7E
#define End_Byte                    0xEF
#define Version                     0xFF
#define Cmd_Len                     0x06
#define Feedback                    0x00              //If need for Feedback: 0x01,  No Feedback: 0

/*----------------------USART���ú� ------------------------*/
#define  USART2_BaudRate  9600
#define  USART_UX         USART2

#define  USART2_TX_PIN				GPIO_Pin_2// TX ����
#define	 USART2_TX_PORT				GPIOA// TX ���Ŷ˿�
#define	 USART2_TX_CLK				RCC_AHB1Periph_GPIOA// TX ����ʱ��
#define  USART2_TX_PinSource        GPIO_PinSource2// ����Դ

#define  USART2_RX_PIN				GPIO_Pin_3// RX ����
#define	 USART2_RX_PORT				GPIOA// RX ���Ŷ˿�
#define	 USART2_RX_CLK				RCC_AHB1Periph_GPIOA// RX ����ʱ��
#define  USART2_RX_PinSource        GPIO_PinSource3// ����Դ

/********************************��������*********************************************************/
void DFPLayer_GPIO_Config(void);//USART2���ų�ʼ��
void DFPlayer_Usart_Config(void);//USART2���ڳ�ʼ��
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);//���ڷ���һ���ֽ�
void send_cmd_sequence(USART_TypeDef * pUSARTx, uint8_t * pData, uint8_t Size);//���ڷ���ָ��
void USART_SendCmd(uint8_t cmd, uint8_t Parameter1, uint8_t Parameter2, uint8_t checksum);
void DF_Playfolder (void);//��������
void DF_Pause (void);//������ͣ
void DF_Previous (void);//��һ��
void DF_Next (void);//��һ��
void DF_Increase_Volume (void);//��������
void DF_Decrease_Volume (void);//������С

#endif /* __DFPLAYER_H_ */