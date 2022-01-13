#include <avr/io.h>
#include <uart0.h>
#include <avr/interrupt.h>


void onDataReceived(uint8_t data)
{
    switch(data)
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
        
        default: uart0_putc(data);
    }
}


void init()
{
	// uart0
	uart0_init(9600, UART_M_TRANSCEIVE, UART_P_EVEN);
    uart0_registerReceptionCallback(&onDataReceived);

    
	sei();
}


int main(void)
{
	init();
	
	while (1);
}