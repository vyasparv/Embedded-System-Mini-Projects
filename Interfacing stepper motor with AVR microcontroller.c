#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	int period;
	DDRC = 0x0F;		/* Make PORTD lower pins as output */
	period = 100;		/* Set period in between two steps */
	while (1)
	{
		/* Rotate Stepper Motor clockwise with Half step sequence */
		for(int i=0;i<12;i++)
		{
			PORTC = 0x09;
			_delay_ms(period);
			PORTC = 0x08;
			_delay_ms(period);
			PORTC = 0x0C;
			_delay_ms(period);
			PORTC = 0x04;
			_delay_ms(period);
			PORTC = 0x06;
			_delay_ms(period);
			PORTC = 0x02;
			_delay_ms(period);
			PORTC = 0x03;
			_delay_ms(period);
			PORTC = 0x01;
			_delay_ms(period);
		}
		PORTC = 0x09;		/* Last step to initial position */
		_delay_ms(period);
		_delay_ms(1000);

		/* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<12;i++)
		{
			PORTC = 0x09;
			_delay_ms(period);
			PORTC = 0x03;
			_delay_ms(period);
			PORTC = 0x06;
			_delay_ms(period);
			PORTC = 0x0C;
			_delay_ms(period);
		}
		PORTC = 0x09;
		_delay_ms(period);
		_delay_ms(1000);
	}
}
command(0X01);//Clearing the display.
_delay_ms(250);
}
}
