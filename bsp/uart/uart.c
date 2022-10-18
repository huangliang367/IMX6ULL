#include "uart.h"
#include "gpio.h"

static void uart_io_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_UART1_TX_DATA_UART1_TX, 0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_TX_DATA_UART1_TX, 0x10B0);
    IOMUXC_SetPinMux(IOMUXC_UART1_RX_DATA_UART1_RX, 0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_RX_DATA_UART1_RX, 0x10B0);
}

static void uart_disable(UART_Type *base)
{
    base->UCR1 &= ~(1 << 0);
}

static void uart_enable(UART_Type *base)
{
    base->UCR1 |= (1 << 0);
}

static void soft_reset(UART_Type *base)
{
    base->UCR2 &= ~(1 << 0);
    while (0 == (base->UCR2 & 0x1));
}

void uart_init(void)
{
    uart_io_init();
    uart_disable(UART1);
    soft_reset(UART1);

    UART1->UCR1 &= ~(1 << 14);
    UART1->UCR2 |= (1 << 1) | (1 << 2) | (1 << 5) | (1 << 14);
    UART1->UCR3 |= (1 << 2);
    
    UART1->UFCR &= ~(7 << 7);
    UART1->UFCR |= (5 << 7);
    UART1->UBIR = 71;
    UART1->UBMR = 3124;

    uart_enable(UART1);
}

void putc(unsigned char c)
{
    while (0 == (UART1->USR2 & 0x8));
    UART1->UTXD = c & 0xFF;   
}

unsigned char getc(void)
{
    while (0 == (UART1->USR2 & 0x1));
    return (UART1->URXD & 0xFF);
}

void puts(char *str)
{
    char *p = str;
    while (*p) {
        putc(*p++);
    }
}

void raise(void)
{
    
}