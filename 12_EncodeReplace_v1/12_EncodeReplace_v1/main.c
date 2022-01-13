/*#include <avr/io.h>
#include <uart0.h>
#include <avr/interrupt.h>

ISR(USART0_RX_vect)
{
	char c = UDR0;
	
	switch(c)
	{
		case 'A': case 'a':
		case 'E': case 'e':
		case 'I': case 'i':
		case 'O': case 'o':
		case 'U': case 'u':
		break;
		
		case 'R': uart0_putc('L');
		break;
		
		case 'r': uart0_putc('l');
		break;
		
		default: uart0_putc(c);
	}
	
}

void init()
{
	// uart0
	uart0_init(9600, UART_M_TRANSCEIVE, UART_P_EVEN);
	
	UCSR0B |= (1 << RXCIE0); // enable recieve interrupt
	sei();
}


int main(void)
{
    init();
	
    while (1) 
    {
    }
}*/