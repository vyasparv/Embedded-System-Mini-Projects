#include<stdio.h>
#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>


int main(void){
	DDRA = 0xFF;
	while(1)
	{
		PORTA =0x00;
		_delay_ms(100);
		PORTA =0x06;
		_delay_ms(100);
		PORTA =0x28;
		_delay_ms(100);
		PORTA =0x1E;
		_delay_ms(100);
		PORTA =0x2D;
		_delay_ms(100);
	}
}

