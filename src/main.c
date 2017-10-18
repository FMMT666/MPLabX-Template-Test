/*
 * File:   main.c
 * Author: FMMT666(ASkr)
 *
 * TESTING TEMPLATE SCRIPT 1
 * 
 * Created on 19. Oktober 2017, 00:49
 */


#include <xc.h>
#include <stdint.h>

#include "configbits.h"
#include "serial.h"


void InitPic()
{
  // UART, 115200, 8N1
  TXSTA   = 0b00100100;  // 8bits, TX on, async, HS
  RCSTA   = 0b10000000;  // RX OFF (B4) (for now)
  BAUDCON = 0b01100000;  // RX & TX quiesc high, 8bit baud
  SPBRGH  = 0;           // unused, just in case...
  SPBRG   = 25;          // 115.38k (@48MHz)
  LATB7   = 1;
  TRISB7  = 0;
}


void main( void )
{
  uint8_t i = 0;

  // Init PIC
  InitPic();

  for(;;)
  {
    serSendByte( i++ );
  }

  return;
}
