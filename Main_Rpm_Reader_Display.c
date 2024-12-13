/*
 * File:   Main_Rpm_Reader_Display.c
 * Author: Pybarguen
 *
 * Created on 12 de Diciembre de 2024, 11:21 AM
 */


// CONFIG1L
#pragma config WDTEN = OFF      // Watchdog Timer (Disabled - Controlled by SWDTEN bit)
#pragma config PLLDIV = 2       // PLL Prescaler Selection bits (Divide by 2 (8 MHz oscillator input))
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset  (Disabled)
#pragma config XINST = OFF      // Extended Instruction Set (Disabled)

// CONFIG1H
#pragma config CPUDIV = OSC3_PLL3// CPU System Clock Postscaler (CPU system clock divide by 3)
#pragma config CP0 = OFF        // Code Protect (Program memory is not code-protected)

// CONFIG2L
#pragma config OSC = INTOSCPLL  // Oscillator (INTOSCPLL)
#pragma config T1DIG = OFF      // T1OSCEN Enforcement (Secondary Oscillator clock source may not be selected)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator (High-power operation)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor (Disabled)
#pragma config IESO = OFF       // Internal External Oscillator Switch Over Mode (Disabled)

// CONFIG2H
#pragma config WDTPS = 1        // Watchdog Postscaler (1:1)

// CONFIG3L
#pragma config DSWDTOSC = INTOSCREF// DSWDT Clock Select (DSWDT uses INTRC)
#pragma config RTCOSC = INTOSCREF// RTCC Clock Select (RTCC uses INTRC)
#pragma config DSBOREN = OFF    // Deep Sleep BOR (Disabled)
#pragma config DSWDTEN = OFF    // Deep Sleep Watchdog Timer (Disabled)
#pragma config DSWDTPS = G2     // Deep Sleep Watchdog Postscaler (1:2,147,483,648 (25.7 days))

// CONFIG3H
#pragma config IOL1WAY = OFF    // IOLOCK One-Way Set Enable bit (The IOLOCK bit (PPSCON<0>) can be set and cleared as needed)
#pragma config MSSP7B_EN = MSK7 // MSSP address masking (7 Bit address masking mode)

// CONFIG4L
#pragma config WPFP = PAGE_15   // Write/Erase Protect Page Start/End Location (Write Protect Program Flash Page 15)
#pragma config WPEND = PAGE_WPFP// Write/Erase Protect Region Select (valid when WPDIS = 0) (Page WPFP<5:0> through Configuration Words erase/write protected)
#pragma config WPCFG = OFF      // Write/Erase Protect Configuration Region (Configuration Words page not erase/write-protected)

// CONFIG4H
#pragma config WPDIS = OFF      // Write Protect Disable bit (WPFP<5:0>/WPEND region ignored)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
//Pins for Display Control
#define CCS LATBbits.LATB2
#define DCs  LATBbits.LATB3
#define RES LATBbits.LATB4

int counter;//Time counter
char character_buffer[];//Buffer to print char in the display
char rpm_value[];//Buffer to print RPM Value in the display

int seconds;//Seconds counter
int value = 0;//Get the TMR0 Value
float rpm_real;

#include <xc.h>
#define _XTAL_FREQ 16000000 //16MHZ
#include <stdio.h>
#include "Fonts.h"
//#include "Image.h"//Image's Buffer 
#include "PIC2XJ50_SPI.h"//SPI library
#include "ST7735.h"//Basic ST7735 Library


//TMR1 INTERRUPT
void __interrupt(high_priority) tcInt(void)
{
    if (TMR1IE && TMR1IF) {  // any timer 0 interrupts?
           
        value = TMR0;//Get the value of TIMER 0 every TMR1 Interrupt
        //YOU CAN TO MODIFY THE INTERUPT TIME USING TMR1 REGISTERS
                     
          counter++;
          //Every 7462 Interrups is one second in the CPU
          //Every second you need to get the value of the TMR0 Using the Encoder Sensor
                  if(counter>=7462)
                  {  
                      counter = 0;
                      seconds = seconds+1;
                      rpm_real = (value/12)*60;                      
                      TMR0 = 0;
                      value = 0;
                  }
          
          //After Five second the PWM works and the MOTOR is ON          
          if(seconds>=5)
          {
         TMR2ON = 1;
         CCPR1L = 0b00111111;  
          }
          //MOTOR ON
          
          //RESET TIMER 1
          TMR1 = 65000;       
          TMR1IF=0;
       
          
        
           

       
    }
   
    return;
}
  

void main(void) {
    
    OSCTUNEbits.PLLEN = 1;//ON Internal OScilator
     RCONbits.IPEN = 0;//Disable Interrupts vector levels
   
     
     //This code is necesary to SET the input for TMR0 Counter and the output for the PWM
    //Mapping TMR0 Input PIN
    TRISBbits.TRISB6 = 1; 
   INTCON = 0x00;
    EECON2 = 0X55;//Write 0x55 EECON2 COntrol memory sequence register
    EECON2 = 0XAA;//Write 0xAA EECON2 COntrol memory sequence register    
    PPSCONbits.IOLOCK = 0;// I/O lock is not active, pin configurations can be changed
    
    RPINR4 = 12;//SET TMR0 PIN
    RPOR13 = 14;//Set PWM Pin
    EECON2 = 0X55;//Write 0x55 EECON2 COntrol memory sequence register
    EECON2 = 0XAA;//Write 0xAA EECON2 COntrol memory sequence register
    PPSCONbits.IOLOCK = 1;//I/O lock is active, RPORx and RPINRx registers are write-protected
  
    //Comparadores OFF
    CM1CON  = 0x00;
    CM2CON  = 0x00;
    
    //SPI
   Spi_init();//start spi interface
   Spi_mode(CPOL_1_CPHA_0);//SPI mode 0 0 
   Spi_clock_mode(SPI_MASTER_CLOCK_DIV_4);//SPI clock = FOSC/4 
   TRISBbits.TRISB2 = 0;
   TRISBbits.TRISB3 = 0;
   TRISBbits.TRISB4 = 0;
   TRISCbits.TRISC0 = 1;
     
    ANCON0  = 0xFF;//All analog Pins are Digital NOW  
 
     TRISAbits.TRISA0 = 1;
     INTCON = 0b11000000;//Habilitadas todas las interrupciones globales  
    //Interrupts and TMR0 Configuration
   
 
    //Enable ST7735 TFT DISPLAY
    __delay_ms(10);
    RES = 1;
    CCS = 1;
    DCs = 0;
    
   //TFT DISPLAY INIT
    ST7735S_Init(ST7735_128_x_160);
    
    
    TRISBbits.TRISB7 = 0;
    
    T0CON =  0b00111000;//TIMeR 0 16 bits
    TMR0L = 0;   
    T0CONbits.TMR0ON = 1;

    T1CON = 00001011;//Se activa el Timer 1, Timer 1 de 16bits, prescaler de 1, fuente de reloj Fosc/4    
    TMR1IF = 0;
    PIE1bits.TMR1IE = 1;//Se activa la interrupcion del TIMER1
    TMR1 = 65000;

    //PWM CONFIGURATION BITS
    TRISCbits.TRISC2 = 0;
    PR2 = 255;     
    T2CON =  0b00000011;    
    CCP1CON = 0b00001100; 
    TCLKCONbits.T3CCP2 = 0; 
    TCLKCONbits.T3CCP1 = 0;
    TCLKCONbits.T1RUN = 0;
    TMR2 = 0;
    
   
 
   
    ST7735S_Fill_display(Background_T);
  //  ST7735S_Fill_image(Image_array);
      while(1)
    {
     
          
          //"RPM_VALUE" is update in TIMER1 Interrupt
     
     ST7735S_Print_String(Blue_Color, "RPM", 0, 100, 2);
     
     sprintf(rpm_value, "%.2f", rpm_real);    
     ST7735S_Print_String(Blue_Color, rpm_value, 0, 120, 2);
     

       
     ST7735S_Print_String(Blue_Color, "Time ", 0, 140, 2);
     
        sprintf(character_buffer, "%d", seconds);    
     ST7735S_Print_String(Blue_Color, character_buffer, 70, 140, 2);
     
     ST7735S_Print_String(Blue_Color, "(s)", 100, 140, 1);
     
    
     
     

         
    }
}