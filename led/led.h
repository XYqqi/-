#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5

/* �͵�ƽʱ��LED���� */
#define ON  1
#define OFF 0
/* ���κ꣬��������������һ��ʹ�� */   
    #define LED00(a) if (a)\
    GPIO_SetBits(LED0_GPIO_PORT,LED0_GPIO_PIN);\
    else \
     GPIO_ResetBits(LED0_GPIO_PORT,LED0_GPIO_PIN)
    #define LED01(a) if (a)\
    GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
    else \
     GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
/* ����LED���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED���� */
// R-��ɫ
#define LED0_GPIO_PORT          GPIOB                       /* GPIO�˿� */
#define LED0_GPIO_CLK           RCC_APB2Periph_GPIOB        /* GPIO�˿�ʱ�� */
#define LED0_GPIO_PIN           GPIO_Pin_5                  /* GPIO�˿� */
// G-��ɫ
#define LED1_GPIO_PORT          GPIOE                       /* GPIO�˿� */
#define LED1_GPIO_CLK           RCC_APB2Periph_GPIOE        /* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN           GPIO_Pin_5                  /* GPIO�˿� */


    
/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define digitalHi(p,i){p->BSRR=i;}      //���Ϊ�ߵ�ƽ
#define digitalLo(p,i){p->BRR=i;}       //����͵�ƽ
#define digitalToggle(p,i){p->ODR ^=i;} //�����ת״̬

/* �������IO�ĺ� */
#define LED0_TOGGLE             digitalToggle(LED0_GPIO_PORT,LED0_GPIO_PIN)
#define LED0_ON                 digitalLo(LED0_GPIO_PORT,LED0_GPIO_PIN)
#define LED0_OFF                digitalHi(LED0_GPIO_PORT,LED0_GPIO_PIN)

#define LED1_TOGGLE             digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON                 digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF                digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)

void LED_Init(void);//��ʼ��

 
#endif
