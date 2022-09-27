#include <stdio.h>
#include "clock.h"
#include "beep.h"
#include "led.h"
#include "morse.h"

int main(int argc, char *argv[])
{
    clk_enable();
    beep_init();
    led_init();

    morse_xfer("helloworld");
    delay_ms(5000);
    morse_xfer("huangliang");

    return 0;
}