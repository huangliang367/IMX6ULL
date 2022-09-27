#include "key.h"
#include "led.h"
#include "beep.h"

void key_test(void)
{
    KEY_STATUS key_status = KEY_RELEASED;
    LED_STATUS led_status = LED_ON;
    BEEP_STATUS beep_status = BEEP_ON;

    key_init();

    while (1) {
        key_status = get_key_status();
        if (KEY_PRESSED == key_status) {
            led_status = !led_status;
            beep_status = !beep_status;
            led_switch(led_status);
            beep_switch(beep_status);
        }
    }
}