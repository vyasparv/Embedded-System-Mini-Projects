// Program to receive data from USART and displaying it on LCD
/*
Receive data from serial port and display it on LCD
LCD DATA port----PORT A
ctrl port------PORT B
rs-------PB0
rw-------PB1
en-------PB2
using external clock frequency 12MHz
*/

#define F_CPU 8000000UL
#define USART_BAUDRATE 9600 // Baud Rate value
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#include<avr/io.h>
#include<util/delay.h>

#define LCD_DATA PORTA //LCD data port

#define ctrl PORTB
#define en PB2 // enable signal
#define rw PB1 // read/write signal
#define rs PB0 // register select signal

void LCD_cmd(unsigned char cmd);
void init_LCD(void);
void LCD_write(unsigned char data);
void LCD_clear();

void usart_init();
void usart_putch(unsigned char send);
unsigned int usart_getch();

int main()
{
	unsigned char value;
	DDRA=0xff; // LCD_DATA port as output port
	DDRB=0x07; // signal as out put
	init_LCD(); //initialization of LCD
	_delay_ms(50); // delay of 50 milli seconds
	usart_init(); // initialization of USART
	while(1)
	{
		value=usart_getch(); // Call a function to get data from serial port
		LCD_cmd(0xC0); // to go in second line and zeroth  position on LCD
		LCD_write(value); // write data to LCD
	}
	return 0;
}

void init_LCD(void)
