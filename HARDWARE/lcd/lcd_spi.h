#ifndef __LCD_SPI_H
#define __LCD_SPI_H

#incldue "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "usart.h" 
#include "lcd_fonts.h"		
#include "lcd_image.h" 

/*----------------------------------------------- ������ -------------------------------------------*/
#define LCD_Width     240		// LCD�����س���
#define LCD_Height    280		// LCD�����ؿ��

// ��ʾ�������
// ʹ��ʾ����LCD_DisplayDirection(Direction_H) ������Ļ������ʾ
#define	Direction_H				0					//LCD������ʾ
#define	Direction_H_Flip	    1					//LCD������ʾ,���·�ת
#define	Direction_V				2					//LCD������ʾ 
#define	Direction_V_Flip	    3					//LCD������ʾ,���·�ת 

// ���ñ�����ʾʱ����λ��0���ǲ��ո�
// ֻ�� LCD_DisplayNumber() ��ʾ���� �� LCD_DisplayDecimals()��ʾС�� �����������õ�
// ʹ��ʾ���� LCD_ShowNumMode(Fill_Zero) ���ö���λ���0������ 123 ������ʾΪ 000123
#define  Fill_Zero  0		//���0
#define  Fill_Space 1		//���ո�

/**
 * ������ɫ��
 *     1. Ϊ�˷���ʹ�ã��������24λ RGB888��ɫ��Ȼ����ͨ�������Զ�ת���� 16λ RGB565 ����ɫ
 *     2. 24λ����ɫ�У��Ӹ�λ����λ�ֱ��Ӧ R��G��B  3����ɫͨ��
 *     3. �ڵ����õ�ɫ���ȡ24λRGB��ɫ���ٽ���ɫ����LCD_SetColor()��LCD_SetBackColor()�Ϳ�����ʾ����Ӧ����ɫ
 */
#define 	LCD_WHITE       0xFFFFFF	 // ����ɫ
#define 	LCD_BLACK       0x000000     // ����ɫ
                        
#define 	LCD_BLUE        0x0000FF	 //	����ɫ
#define 	LCD_GREEN       0x00FF00     //	����ɫ
#define 	LCD_RED         0xFF0000     //	����ɫ
#define 	LCD_CYAN        0x00FFFF     //	����ɫ
#define 	LCD_MAGENTA     0xFF00FF     //	�Ϻ�ɫ
#define 	LCD_YELLOW      0xFFFF00     //	��ɫ
#define 	LCD_GREY        0x2C2C2C     //	��ɫ
												
#define 	LIGHT_BLUE      0x8080FF     //	����ɫ
#define 	LIGHT_GREEN     0x80FF80     //	����ɫ
#define 	LIGHT_RED       0xFF8080     //	����ɫ
#define 	LIGHT_CYAN      0x80FFFF     //	������ɫ
#define 	LIGHT_MAGENTA   0xFF80FF     //	���Ϻ�ɫ
#define 	LIGHT_YELLOW    0xFFFF80     //	����ɫ
#define 	LIGHT_GREY      0xA3A3A3     //	����ɫ
												
#define 	DARK_BLUE       0x000080     //	����ɫ
#define 	DARK_GREEN      0x008000     //	����ɫ
#define 	DARK_RED        0x800000     //	����ɫ
#define 	DARK_CYAN       0x008080     //	������ɫ
#define 	DARK_MAGENTA    0x800080     //	���Ϻ�ɫ
#define 	DARK_YELLOW     0x808000     //	����ɫ
#define 	DARK_GREY       0x404040     //	����ɫ

/*------------------------------------------------ �������� ----------------------------------------------*/
void  SPI_LCD_Init(void);// Һ�����Լ�SPI��ʼ��   
void  LCD_Clear(void);// ��������
void  LCD_ClearRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height);// �ֲ���������
void  LCD_SetAddress(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);	// ��������		
void  LCD_SetColor(uint32_t Color);// ���û�����ɫ
void  LCD_SetBackColor(uint32_t Color);// ���ñ�����ɫ
void  LCD_SetDirection(uint8_t direction);// ������ʾ����
//>>>>>	��ʾASCII�ַ�
void  LCD_SetAsciiFont(pFONT *fonts);// ����ASCII����
void  LCD_DisplayChar(uint16_t x, uint16_t y,uint8_t c);// ��ʾ����ASCII�ַ�
void  LCD_DisplayString( uint16_t x, uint16_t y, char *p);// ��ʾASCII�ַ���
//>>>>>	��ʾ�����ַ�������ASCII��
void  LCD_SetTextFont(pFONT *fonts);// �����ı����壬�������ĺ�ASCII����
void  LCD_DisplayChinese(uint16_t x, uint16_t y, char *pText);// ��ʾ��������
void  LCD_DisplayText(uint16_t x, uint16_t y, char *pText);// ��ʾ�ַ������������ĺ�ASCII�ַ�
//>>>>>	��ʾ������С��
void  LCD_ShowNumMode(uint8_t mode);// ���ñ�����ʾģʽ������λ���ո������0
void  LCD_DisplayNumber( uint16_t x, uint16_t y, int32_t number,uint8_t len);// ��ʾ����
void  LCD_DisplayDecimals( uint16_t x, uint16_t y, double number,uint8_t len,uint8_t decs);// ��ʾС��
//>>>>>	2Dͼ�κ���
void  LCD_DrawPoint(uint16_t x,uint16_t y,uint32_t color);//����
void  LCD_DrawLine_V(uint16_t x, uint16_t y, uint16_t height);// ����ֱ��
void  LCD_DrawLine_H(uint16_t x, uint16_t y, uint16_t width);// ��ˮƽ��
void  LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);// ����֮�仭��
void  LCD_DrawRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height);//������
void  LCD_DrawCircle(uint16_t x, uint16_t y, uint16_t r);//��Բ
void  LCD_DrawEllipse(int x, int y, int r1, int r2);//����Բ
//>>>>>	������亯��
void  LCD_FillRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height);//������
void  LCD_FillCircle(uint16_t x, uint16_t y, uint16_t r);//���Բ
//>>>>>	���Ƶ�ɫͼƬ
void  LCD_DrawImage(uint16_t x,uint16_t y,uint16_t width,uint16_t height,const uint8_t *pImage);

/*------------------------------------------------------  �������ú� -------------------------------------------------*/
#define 	LCD_SPI      SPI3// LCD�õ�����SPI3
#define	    LCD_SPI_APBClock_Enable 	RCC_APB1PeriphClockCmd ( RCC_APB1Periph_SPI3,ENABLE )// ʹ������ʱ��

#define 	LCD_SCK_PIN      		 		GPIO_Pin_3// SCK���ţ� ��Ҫ�ض���SPI1��IO�ڸ���
#define 	LCD_SCK_PORT     		 		GPIOB// SCK�����õ��Ķ˿�  
#define 	GPIO_LCD_SCK_CLK      			RCC_AHB1Periph_GPIOB// SCK����IO��ʱ��
#define 	GPIO_LCD_SCK_PinSource       	GPIO_PinSource3
#define 	GPIO_LCD_SCK_AF              	GPIO_AF_SPI3

#define 	LCD_SDA_PIN      		 		GPIO_Pin_5// SDA���ţ� ��Ҫ�ض���SPI1��IO�ڸ���
#define 	LCD_SDA_PORT    		 		GPIOB// SDA�����õ��Ķ˿�  
#define 	GPIO_LCD_SDA_CLK      			RCC_AHB1Periph_GPIOB// SDA����IO��ʱ��
#define 	GPIO_LCD_SDA_PinSource       	GPIO_PinSource5
#define 	GPIO_LCD_SDA_AF              	GPIO_AF_SPI3

#define 	LCD_CS_PIN       				GPIO_Pin_11// CSƬѡ���ţ��͵�ƽ��Ч
#define 	LCD_CS_PORT      				GPIOD// CS�����õ��Ķ˿� 
#define 	GPIO_LCD_CS_CLK     			RCC_AHB1Periph_GPIOD// CS����IO��ʱ��

#define     LCD_DC_PIN						GPIO_Pin_12// ����ָ��ѡ������				
#define	    LCD_DC_PORT						GPIOD// ����ָ��ѡ��GPIO�˿�
#define 	GPIO_LCD_DC_CLK     			RCC_AHB1Periph_GPIOD// ����ָ��ѡ��GPIOʱ�� 	

#define     LCD_Backlight_PIN				GPIO_Pin_13//��������				
#define	    LCD_Backlight_PORT			    GPIOD// ����GPIO�˿�
#define 	GPIO_LCD_Backlight_CLK          RCC_AHB1Periph_GPIOD// ����GPIOʱ��

/*--------------------------------------------------------- ���ƺ� ---------------------------------------------------*/
#define 	LCD_CS_H    		 	LCD_CS_PORT->BSRRL  = LCD_CS_PIN// Ƭѡ����
#define 	LCD_CS_L     			LCD_CS_PORT->BSRRH  = LCD_CS_PIN// Ƭѡ����

#define	    LCD_DC_Command		   GPIO_ResetBits(LCD_DC_PORT, LCD_DC_PIN)// �͵�ƽ��ָ��� 
#define 	LCD_DC_Data		       GPIO_SetBits(LCD_DC_PORT, LCD_DC_PIN)// �ߵ�ƽ�����ݴ���

#define 	LCD_Backlight_ON       GPIO_SetBits(LCD_Backlight_PORT,LCD_Backlight_PIN)// �ߵ�ƽ����������
#define 	LCD_Backlight_OFF  	   GPIO_ResetBits(LCD_Backlight_PORT,LCD_Backlight_PIN)// �͵�ƽ���رձ���

#endif /* __LCD_SPI_H */