#include <LPC21xx.H>

#define LED_PIN (1 << 16)  // P1.16

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 6000; j++); // Rough delay
}

void UART0_Init(void)
{
    PINSEL0 |= 0x00000005; // Enable TxD0 (P0.0) and RxD0 (P0.1)
    U0LCR = 0x83;          // Enable DLAB, 8-bit data
    U0DLM = 0;
    U0DLL = 97;            // 9600 Baud rate for 15MHz PCLK
    U0LCR = 0x03;          // Disable DLAB
}

void UART0_SendChar(char c)
{
    while (!(U0LSR & 0x20)); // Wait for THR to be empty
    U0THR = c;
}

void UART0_SendString(char *str)
{
    while (*str)
        UART0_SendChar(*str++);
}

char UART0_ReceiveChar(void)
{
    while (!(U0LSR & 0x01)); // Wait until data is received
    return U0RBR;
}

int main()
{
    // Initialize UART0
    UART0_Init();

    // Configure P1.16 as output
    IODIR1 |= LED_PIN;

    UART0_SendString("Bluetooth LED Control Ready\r\n");

    while (1)
    {
        char cmd = UART0_ReceiveChar();

        if (cmd == '1')
        {
            IOSET1 = LED_PIN; // Turn ON LED
            UART0_SendString("LED ON\r\n");
        }
        else if (cmd == '0')
        {
            IOCLR1 = LED_PIN; // Turn OFF LED
            UART0_SendString("LED OFF\r\n");
        }
        else
        {
            UART0_SendString("Invalid Command\r\n");
        }
    }
}
