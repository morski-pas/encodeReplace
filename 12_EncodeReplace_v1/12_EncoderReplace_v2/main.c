#include <avr/io.h>
#include <uart0.h>
#include <avr/interrupt.h>

// Library
void (*pRecepionCallback)(uint8_t data) = NULL; // null indicated that no callback function has been registered yet

void uart0_registerReceptionCallback(void (*pCallback)(uint8_t data))
{
    if(pCallback)
        UCSR0B |= (1 << RXCIE0); // enable reception callback

    else
        UCSR0B &= ~(1 << RXCIE0); // disable reception callback
    
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
    if(pRecepionCallback)
    {
        (*pRecepionCallback)(UDR0);
    }
}