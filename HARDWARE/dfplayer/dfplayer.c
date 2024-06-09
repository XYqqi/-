#include "dfplayer.h"
#include "delay.h"


/*************************************************************************************************
*	�� �� ��:	DFPLayer_GPIO_Config
*
*	�� �� ֵ:	��
*
*	��������:	usart2 IO�ڳ�ʼ��
*	
*************************************************************************************************/
static void DFPLayer_GPIO_Config	(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd ( USART2_TX_CLK|USART2_RX_CLK, ENABLE);//IO��ʱ������

	//IO����
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;//����ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//����
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;//����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;//�ٶȵȼ�

	//��ʼ�� TX	����
	GPIO_InitStructure.GPIO_Pin = USART2_TX_PIN;	 
	GPIO_Init(USART2_TX_PORT, &GPIO_InitStructure);	
	//��ʼ�� RX ����													   
	GPIO_InitStructure.GPIO_Pin = USART2_RX_PIN;	
	GPIO_Init(USART2_RX_PORT, &GPIO_InitStructure);		
	
	//IO���ã����õ�USART2
	GPIO_PinAFConfig(USART2_TX_PORT,USART2_TX_PinSource,GPIO_AF_USART2); 
	GPIO_PinAFConfig(USART2_RX_PORT,USART2_RX_PinSource,GPIO_AF_USART2);	
}

/*************************************************************************************************
*	�� �� ��:	DFPlayer_Usart_Config
*
*	�� �� ֵ:	��
*
*	��������:	usart2��ʼ��
*	
*************************************************************************************************/
void DFPlayer_Usart_Config(void)
{		
	USART_InitTypeDef USART_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	// IO�ڳ�ʼ��
	DFPLayer_GPIO_Config();
		 
	// ���ô��ڸ������
	USART_InitStructure.USART_BaudRate 	 = USART2_BaudRate; //������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ8λ
	USART_InitStructure.USART_StopBits   = USART_StopBits_1; //ֹͣλ1λ
	USART_InitStructure.USART_Parity     = USART_Parity_No ; //��У��
	USART_InitStructure.USART_Mode 	    = USART_Mode_Rx | USART_Mode_Tx; //���ͺͽ���ģʽ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // ��ʹ��Ӳ��������
	
	USART_Init(USART2,&USART_InitStructure); //��ʼ������1
	USART_Cmd(USART2,ENABLE);	//ʹ�ܴ���1
}

/*****************************************************************************************
*	�� �� ��: USART_SendCmd
*	��ڲ���: cmd - ����ָ��
*            Parameter1 - ��ѯ�����ݸ��ֽ�(����������)
*            Parameter2 - ��ѯ�����ݵ��ֽ�
*            checksum - �ۼӺ�У��[������ʼλ$] 
*	�� �� ֵ: ��
*	��������: ͨ��������DFPlayerģ�鷢�Ϳ���ָ��
*	˵    ��: ��
******************************************************************************************/
void USART_SendCmd(uint8_t cmd, uint8_t Parameter1, uint8_t Parameter2, uint8_t checksum)
{
    uint16_t Checksum = Version + Cmd_Len + cmd + Feedback + Parameter1 + Parameter2;
    Checksum = 0-Checksum;

    uint8_t CmdSequence[10] = { Start_Byte, Version, Cmd_Len, cmd, Feedback, Parameter1, Parameter2, (Checksum>>8)&0x00ff, (Checksum&0x00ff), End_Byte};

    send_cmd_sequence(USART_UX, CmdSequence, 10);
}

//����2����һ���ֽ�
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
    /* ����һ���ֽ����ݵ�USART */
    USART_SendData(pUSARTx,ch);

    /* �ȴ��������ݼĴ���Ϊ�� */
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

//����2����ָ��
void send_cmd_sequence(USART_TypeDef * pUSARTx, uint8_t * pData, uint8_t Size)
{
    uint8_t i;
    for(i=0; i<Size; i++)
    {
        Usart_SendByte( pUSARTx, pData[i]);
    }
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

//��������
void DF_Playfolder (void)
{
    USART_SendCmd(0x0D,0x00,0x01, 0xED);
    Delay_ms(200);
}

//������ͣ
void DF_Pause (void)
{
    USART_SendCmd(0x0E,0x00,0x00,0xED);
    Delay_ms(200);
}

//��һ��
void DF_Previous (void)
{
    USART_SendCmd(0x02,0x00,0x01,0xF8);
    Delay_ms(200);
}

//��һ��
void DF_Next (void)
{
    USART_SendCmd(0x01, 0x00, 0x01, 0xF9);
    Delay_ms(200);
}

//��������
void DF_Increase_Volume (void)
{
    USART_SendCmd(0x04, 0x00, 0x00, 0xF7);
    Delay_ms(200);
}

//������С
void DF_Decrease_Volume (void)
{
    USART_SendCmd(0x05, 0x00, 0x00, 0xF6);
    Delay_ms(200);
}


