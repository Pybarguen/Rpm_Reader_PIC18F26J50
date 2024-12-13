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
 * Author: Daniel Andres Ibarguen Mosquera
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
#include <xc.h> // include processor files - each processor file is guarded.  

/*SPI modes you can see how the SPI modes work here
 https://en.wikipedia.org/wiki/Serial_Peripheral_Interface*/
enum SPI_MODES{
           CPOL_0_CPHA_0, 
           CPOL_0_CPHA_1,
           CPOL_1_CPHA_0,
           CPOL_1_CPHA_1};
           
 enum Spi_master_clock_modes{
     
     SPI_MASTER_CLOCK_DIV_4,             
     SPI_MASTER_CLOCK_DIV_16,
     SPI_MASTER_CLOCK_DIV_64,
     SPI_MASTER_CLOCK_DI_TMR2_2
             
     
     
     
 };       

           
           
           
void Spi_init()
{
    
    TRISCbits.TRISC7 = 0;//Pin SDO    
    TRISBbits.TRISB5 = 1;//Pin SDI
    TRISBbits.TRISB4 = 0;//Pin SCL
    
    SSPCON1bits.SSPEN = 1;//SPI Enable
}

void Spi_mode(enum SPI_MODES data)
{
    if(data == CPOL_0_CPHA_0)
    {
       
        SSPCON1bits.CKP = 0;
        SSPSTATbits.CKE = 0;
     
    }
    else if(data == CPOL_0_CPHA_1)
    {
        
          SSPCON1bits.CKP = 0;
          SSPSTATbits.CKE = 1;
    }
    else if(data == CPOL_1_CPHA_0)
    {
        
           SSPCON1bits.CKP = 1;
          SSPSTATbits.CKE = 0;
    }
    
    else if(data == CPOL_1_CPHA_1)
    {
        
       SSPCON1bits.CKP = 1;
           SSPSTATbits.CKE = 1;
    }
}

void Spi_clock_mode(enum Spi_master_clock_modes data)

{
    if(data == SPI_MASTER_CLOCK_DIV_4)
    {
        
      SSPM01 = 0;
      SSPM11 = 0;
      SSPM21 = 0;
      SSPM31 = 0;
      
    }
    
      if(data == SPI_MASTER_CLOCK_DIV_16)
    {
        SSPM01 = 1;
      SSPM11 = 0;
      SSPM21 = 0;
      SSPM31 = 0;
    
      
      
    }
    
       if(data == SPI_MASTER_CLOCK_DIV_64)
    {
        
      SSPM01 = 0;
      SSPM11 = 1;
      SSPM21 = 0;
      SSPM31 = 0;
      
      
      
      
    }
    
        if(data == SPI_MASTER_CLOCK_DI_TMR2_2)
    {
        
      SSPM01 = 1;
      SSPM11 = 1;
      SSPM21 = 0;
      SSPM31 = 0;
     
      
      
    }
    
    
}

void write_command(int command)
{
 
     CCS = 0;
    SSPBUF =  command;
    while(SSPSTATbits.BF == 0);
    while(PIR1bits.SSPIF == 0);
    PIR1bits.SSPIF = 0;
     CCS = 1;
  
     
    
    
}

void write_data(int data)
{
   
    
     CCS = 0;
    SSPBUF =  data;
    while(SSPSTATbits.BF == 0);
    while(PIR1bits.SSPIF == 0);
    PIR1bits.SSPIF = 0;
     CCS = 1;
     
    
    
}



#endif	/* XC_HEADER_TEMPLATE_H */

