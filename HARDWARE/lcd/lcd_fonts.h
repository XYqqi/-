#ifndef __LCD_FONTS_H
#define __LCD_FONTS_H

#include <stdint.h>

// 字体相关结构定义
typedef struct _pFont
{    
	const uint8_t 		*pTable;  		//	字模数组地址
	uint16_t 			Width; 		 	//	单个字符的字模宽度
	uint16_t 			Height; 		//	单个字符的字模长度
	uint16_t 			Sizes;	 		//	单个字符的字模数据个数
	uint16_t			Table_Rows;		// 该参数只有汉字字模用到，表示二维数组的行大小
} pFONT;

/*------------------------------------ 中文字体 ---------------------------------------------*/
extern	pFONT	CH_Font12 ;		//	12*12字体
extern	pFONT	CH_Font16 ;     //	16*16字体
extern	pFONT	CH_Font20 ;     //	20*20字体
extern	pFONT	CH_Font24 ;     //	24*24字体
extern	pFONT	CH_Font32 ;     //	32*32字体

/*------------------------------------ ASCII字体 ---------------------------------------------*/
extern pFONT ASCII_Font32;		// 32*16 字体
extern pFONT ASCII_Font24;		// 24*12 字体
extern pFONT ASCII_Font20; 	    // 20*10 字体
extern pFONT ASCII_Font16; 	    // 16*08 字体
extern pFONT ASCII_Font12; 	    // 12*06 字体


#endif /* __LCD_FONTS_H */