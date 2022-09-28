#include <stdio.h>
#include "clock.h"
#include "beep.h"
#include "led.h"
#include "morse.h"
#include "key_test.h"

static void board_init(void)
{
    imx6ull_clk_init();
    clk_enable();
    beep_init();
    led_init();
}

int main(int argc, char *argv[])
{
    board_init();
    morse_xfer("helloworld");
    key_test();

    return 0;
}