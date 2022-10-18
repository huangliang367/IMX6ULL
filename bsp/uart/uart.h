#ifndef _UART_H
#define _UART_H
#include "imx6ull.h"

void uart_init(void);
void putc(unsigned char c);
unsigned char getc(void);
void puts(char *str);

#endif /* _UART_H */