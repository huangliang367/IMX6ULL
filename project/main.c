#include <stdio.h>
#include "clock.h"
#include "beep.h"
#include "led.h"
#include "morse.h"
#include "key_test.h"

static void dev_init(void)
{
    clk_enable();
    beep_init();
    led_init();
}

int main(int argc, char *argv[])
{
    dev_init();

    morse_xfer("helloworld");
    delay_ms(1000);
    morse_xfer("huangliang");

    key_test();

    return 0;
}