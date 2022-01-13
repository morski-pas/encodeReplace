#include <avr/io.h>
#include <uart0.h>
#include <avr/interrupt.h>

// Library
void (*pRecepionCallback)(uint8_t data);

void uart0_registerReceptionCallback(void (*pCallback)(uint8_t data))
{
    pRecepionCallback = pCallback;
}




// Application
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
	
	UCSR0B |= (1 << RXCIE0); // enable receive interrupt
    
    uart0_registerReceptionCallback(&onDataReceived);
	sei();
}


int main(void)
{
	init();
	
	while (1);
}


ISR(USART0_RX_vect)
{
    (*pRecepionCallback)(UDR0);
}