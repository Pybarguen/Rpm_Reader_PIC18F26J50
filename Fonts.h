/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef Fonts.h
#define	Fonts.h
#include <xc.h> // include processor files - each processor file is guarded.


//16bits Colors
#define Red_Color   0b0000011111111111
#define Green_Color 0b1111100000011111                   
#define Blue_Color 0xFFE0
#define Black_Color 0xFFFF
#define White_Color 0x0000
#define Background_T 0b1101111011011011

//matrix for ASCII Characters
char *const font[126][5] = 
{
0x00, 0x00, 0x00, 0x00, 0x00,//0
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,//5
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,//10
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,//15
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,//20
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,//25
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,//30
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFB, 0x00, 0x00,
0x00, 0x6F, 0x00, 0x6F, 0x00,
0x28, 0xFE, 0x28, 0xFE, 0x28,//35
0x00, 0X72, 0xCB, 0x4E, 0x00, 
0x46, 0X26, 0x10, 0xC8, 0xC4,
0x36, 0X49, 0x55, 0x22, 0x05, 
0x00, 0X00, 0x00, 0x0E, 0x00,
0x00, 0X3C, 0x42, 0x81, 0x00,//40
0x00, 0X81, 0x42, 0x3C, 0x00, 
0x44, 0X28, 0x16, 0x28, 0x44,
0x10, 0X10, 0xFE, 0x10, 0x10,
0xB0, 0X70, 0x00, 0x00, 0x00,
0x08, 0X08, 0x08, 0x08, 0x08,//45
0x80, 0X00, 0x00, 0x00, 0x00,
0x08, 0X08, 0x08, 0x08, 0x08,
0x7E, 0X81, 0x81, 0x81, 0x7E,
0x84, 0X82, 0xFF, 0x80, 0x80,
0xC6, 0XA1, 0x91, 0x89, 0x86,//50
0x42, 0X81, 0x89, 0x89, 0x7E,
0x08, 0X0C, 0x0A, 0xFF, 0x08,
0x00, 0X9F, 0x91, 0x91, 0xF1,
0x7E, 0X91, 0x91, 0x91, 0x72,
0x03, 0X01, 0x01, 0x01, 0xFF,//55
0x7E, 0X91, 0x91, 0x91, 0x7E,
0x0F, 0X09, 0x09, 0x09, 0xFF,
0x00, 0X00, 0x66, 0x00, 0x00,
0xB4, 0X70, 0x00, 0x00, 0x00,
0x10, 0X28, 0x44, 0x82, 0x00,//60
0x14, 0X14, 0x14, 0x14, 0x14,
0x00, 0X82, 0x44, 0x28, 0x10,        
0x06, 0X01, 0xB1, 0x09, 0x06,
0x7E, 0X81, 0x9D, 0x95, 0x1E,
0xFE, 0X11, 0x11, 0x11, 0xFE,//65
0xFF, 0X89, 0x89, 0x89, 0x76,
0x7E, 0X81, 0x81, 0x81, 0x66,
0xFF, 0X81, 0x81, 0x42, 0x3C,
0x7E, 0X89, 0x89, 0x89, 0x89,
0xFF, 0X09, 0x09, 0x01, 0x01,//70
0x7E, 0X081,0xB1, 0x91, 0xF1,
0xFF, 0X08, 0x08, 0x08, 0xFF,
0x00, 0X00, 0xFF, 0x00, 0x00,//Fix
0x61, 0X81, 0x81, 0xFF, 0x00,//Fix
0xFF, 0X18, 0x24, 0x42, 0x81,//75
0xFF, 0X80, 0x80, 0x80, 0x80,
0xFF, 0X02, 0x04, 0x02, 0xFF,
0xFF, 0X02, 0x04, 0x08, 0xFF,
0xFF, 0X81, 0x81, 0x81, 0xFF,
0xFF, 0X09, 0x09, 0x09, 0x06,//80
0x3E, 0X41, 0x51, 0x61, 0xBE,
0xFF, 0X09, 0x09, 0x09, 0xF6,
0x7E, 0X81, 0x81, 0x81, 0x66,
0x01, 0X01, 0xFF, 0x01, 0x01,
0x7F, 0X80, 0x80, 0x80, 0x7F,//85
0x7E, 0X81, 0x81, 0x81, 0x66,
0x7F, 0X80, 0xF0, 0x80, 0x7F,     
0xC6, 0X28, 0x10, 0x28, 0xC6,
0x80, 0X47, 0x28, 0x10, 0x0F,
0xC3, 0XA1, 0x91, 0x89, 0xC7,//90
0xFF, 0X81, 0x81, 0x00, 0x00,
0x04, 0X08, 0x10, 0x20, 0x40,
0x81, 0X81, 0xFF, 0x00, 0x00,
0x08, 0X04, 0x02, 0x04, 0x08,
0x80, 0X80, 0x80, 0x80, 0x80,//95
0x00, 0X00, 0x03, 0x07, 0x0C,
0x74, 0X92, 0x92, 0x7C, 0x80,
0x7F, 0X90, 0x90, 0x90, 0x60,
0x7C, 0X82, 0x82, 0x82, 0x44,
0x60, 0X90, 0x90, 0x90, 0x7F,//100
0x7C, 0X8A, 0x8A, 0x8A, 0x0C,
0x08, 0XFE, 0x09, 0x01, 0x01,
0x4C, 0X92, 0x92, 0x92, 0xFF,
0xFF, 0X10, 0x08, 0x08, 0xF0,
0x00, 0X00, 0xFD, 0x00, 0x00,//105
0x60, 0X80, 0x80, 0xFD, 0x00,
0xFE, 0X10, 0x28, 0x44, 0x82,
0xFE, 0X80, 0x80, 0x80, 0x00,
0xFE, 0X04, 0x08, 0x04, 0xFE,
0xFE, 0X30, 0x08, 0x08, 0xF0,//110
0xFE, 0X82, 0x82, 0x82, 0xFE,
0xFF, 0X12, 0x12, 0x12, 0x0C,
0x0C, 0X12, 0x12, 0x12, 0xFF,
0xFE, 0X08, 0x04, 0x02, 0x04,
0x5C, 0X92, 0x92, 0x92, 0xE4,//115
0x08, 0XFF, 0x88, 0x88, 0x40,
0x7E, 0X80, 0x80, 0x80, 0x7E,
0x3E, 0X40, 0x80, 0x40, 0x3E,
0x7E, 0X80, 0xF0, 0x80, 0x7E,
0xC6, 0X28, 0x10, 0x28, 0xC6,//120
0x80, 0X47, 0x28, 0x10, 0x0F,
0xC3, 0XA1, 0x91, 0x89, 0xC7,
0x00, 0x18, 0x7E, 0x81, 0x00,
0x00, 0x00, 0xFF, 0x00, 0x00,
0X00, 0X81, 0X7E, 0X18, 0X00//125



};

#endif	/* XC_HEADER_TEMPLATE_H */

