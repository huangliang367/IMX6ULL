#include "clock.h"
#include "beep.h"
#include "led.h"
#include "morse.h"
#include "key_test.h"
#include "int.h"
#include "uart.h"
#include "stdio.h"

static void board_init(void)
{
    int_init();
    imx6ull_clk_init();
    clk_enable();
    uart_init();
    beep_init();
    led_init();
}

int main(int argc, char *argv[])
{
    unsigned char c = 0;

    board_init();
    morse_xfer("helloworld");
    key_test();
    
    while (1) {
        printf("#");
        c = getc();
        printf("%c\r\n", c);
    }

    return 0;
}