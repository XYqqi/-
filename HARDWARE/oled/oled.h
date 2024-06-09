#ifndef __OLED_H
#define __OLED_H

#include "stm32f4xx.h"
#include <stdint.h>
#include "oledData.h"

/*****************参数宏定义*********************/
/* FontSize参数取值,此参数值不仅用于判断，而且用于计算横向字符偏移，默认值为字体像素宽度 */
#define OLED_8X16				8
#define OLED_6X8				6
/* IsFilled参数数值 */
#define OLED_UNFILLED			0
#define OLED_FILLED				1
/*****************参数宏定义*********************/

/*****************IIC接口宏定义*****************/
#define       OLED_IIC_SCL_PORT                     GPIOB
#define       OLED_IIC_SCL_PIN                      GPIO_Pin_6
#define       OLED_IIC_SCL_CLK                      RCC_AHB1Periph_GPIOB


#define       OLED_IIC_SDA_PORT                     GPIOB
#define       OLED_IIC_SDA_PIN                      GPIO_Pin_7
#define       OLED_IIC_SDA_CLK                      RCC_AHB1Periph_GPIOB
/*****************IIC接口宏定义*****************/

/*******************函数声明*******************/
/* 初始化函数 */
void OLED_Init(void);
/* 更新函数 */
void OLED_Update(void);//更新整个屏幕数据
void OLED_UpdateArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height);//更新部分屏幕数据
/* 显存控制函数 */
void OLED_Clear(void);//清除整个屏幕
void OLED_ClearArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height);//清除部分屏幕
void OLED_Reverse(void);//将OLED显存数组全部取反
void OLED_ReverseArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height);//将OLED显存数组部分取反
/* 显示函数 */
void OLED_ShowChar(uint8_t X, uint8_t Y, char Char, uint8_t FontSize);
void OLED_ShowString(uint8_t X, uint8_t Y, char *String, uint8_t FontSize);
void OLED_ShowNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowSignedNum(uint8_t X, uint8_t Y, int32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowHexNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowBinNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowFloatNum(uint8_t X, uint8_t Y, double Number, uint8_t IntLength, uint8_t FraLength, uint8_t FontSize);
void OLED_ShowChinese(uint8_t X, uint8_t Y, char *Chinese);
void OLED_ShowImage(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, const uint8_t *Image);
void OLED_Printf(uint8_t X, uint8_t Y, uint8_t FontSize, char *format, ...);
/* 绘图函数 */
void OLED_DrawPoint(uint8_t X, uint8_t Y);
uint8_t OLED_GetPoint(uint8_t X, uint8_t Y);
void OLED_DrawLine(uint8_t X0, uint8_t Y0, uint8_t X1, uint8_t Y1);
void OLED_DrawRectangle(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, uint8_t IsFilled);
void OLED_DrawTriangle(uint8_t X0, uint8_t Y0, uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t IsFilled);
void OLED_DrawCircle(uint8_t X, uint8_t Y, uint8_t Radius, uint8_t IsFilled);
void OLED_DrawEllipse(uint8_t X, uint8_t Y, uint8_t A, uint8_t B, uint8_t IsFilled);
void OLED_DrawArc(uint8_t X, uint8_t Y, uint8_t Radius, int16_t StartAngle, int16_t EndAngle, uint8_t IsFilled);
/*******************函数声明*******************/


#endif // __OLED_H