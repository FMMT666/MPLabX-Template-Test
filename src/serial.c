/*
 * File:   serial.c
 * Author: FMMT666(ASkr)
 *
 * Created on 11. Dezember 2016, 00:20
 */

#include <xc.h>
#include <stdint.h>
#include <stddef.h>

#include "serial.h"


//**************************************************************************************
//***
//***
//***
//**************************************************************************************
void serSendByte( uint8_t ch )
{
	while( TX1IF == 0)
	{;}	
	TXREG = ch;
}



//**************************************************************************************
//***
//***
//***
//**************************************************************************************
void serSendString( uint8_t *ch )
{
	if( ch != NULL )
		while( *ch != 0 )
			serSendByte(*ch++);
}



//**************************************************************************************
//***
//***
//***
//**************************************************************************************
void serSendStringDebug( uint8_t *ch1, int32_t val, uint8_t *ch2)
{
	uint8_t tmp[30];
	uint8_t *p1;
	
	if( ch1 != NULL )
		while( *ch1 != 0 )
			serSendByte( *ch1++ );

	if( val != NUMERR_LONG )
	{
		p1 = (uint8_t *)lltoa( (uint8_t *)&tmp,val );
		while( *p1 != NULL )
			serSendByte( *p1++ );
	}

	if( ch2 != NULL )
		while( *ch2 != 0 )
			serSendByte( *ch2++ );
}


//**************************************************************************************
//*** lltoa()
//***
//*** This might overflow!
//**************************************************************************************
uint8_t *lltoa( uint8_t *buffer, long i )
{
	unsigned long n;
	unsigned int negate = 0;
	int c = 24;

	if (i < 0)
	{
		negate=1;
		n = -i;
	}
	else
		if (i == 0)
		{
			buffer[0] = '0';
			buffer[1] = 0;
			return buffer;
		}
		else
		{
			n = (unsigned long)i;
		}
	
	buffer[c--] = 0;
	do
	{
		buffer[c--] = (n % 10) + '0';
		n = n / 10;
	} while (n);
	
	if (negate)
	{
		buffer[c--] = '-';
	}

	return &buffer[c+1];
}

