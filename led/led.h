#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5

/* 低电平时，LED灯亮 */
#define ON  1
#define OFF 0
/* 带参宏，可以像内联函数一样使用 */   
    #define LED00(a) if (a)\
    GPIO_SetBits(LED0_GPIO_PORT,LED0_GPIO_PIN);\
    else \
     GPIO_ResetBits(LED0_GPIO_PORT,LED0_GPIO_PIN)
    #define LED01(a) if (a)\
    GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
    else \
     GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */
// R-红色
#define LED0_GPIO_PORT          GPIOB                       /* GPIO端口 */
#define LED0_GPIO_CLK           RCC_APB2Periph_GPIOB        /* GPIO端口时钟 */
#define LED0_GPIO_PIN           GPIO_Pin_5                  /* GPIO端口 */
// G-绿色
#define LED1_GPIO_PORT          GPIOE                       /* GPIO端口 */
#define LED1_GPIO_CLK           RCC_APB2Periph_GPIOE        /* GPIO端口时钟 */
#define LED1_GPIO_PIN           GPIO_Pin_5                  /* GPIO端口 */


    
/* 直接操作寄存器的方法控制IO */
#define digitalHi(p,i){p->BSRR=i;}      //输出为高电平
#define digitalLo(p,i){p->BRR=i;}       //输出低电平
#define digitalToggle(p,i){p->ODR ^=i;} //输出反转状态

/* 定义控制IO的宏 */
#define LED0_TOGGLE             digitalToggle(LED0_GPIO_PORT,LED0_GPIO_PIN)
#define LED0_ON                 digitalLo(LED0_GPIO_PORT,LED0_GPIO_PIN)
#define LED0_OFF                digitalHi(LED0_GPIO_PORT,LED0_GPIO_PIN)

#define LED1_TOGGLE             digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON                 digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF                digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)

void LED_Init(void);//初始化

 
#endif
