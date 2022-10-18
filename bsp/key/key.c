#include "imx6ull.h"
#include "gpio.h"
#include "key.h"
#include "clock.h"
#include "int.h"
#include "led.h"
#include "beep.h"

void key_isr(unsigned int gicciar, void *param)
{
    static unsigned int status = 0;

    delay_ms(10);
    if (0 == gpio_pin_read(GPIO1, 18)) {
        led_switch(status);
        beep_switch(status);
        status = !status;
    }

    gpio_clear_int_flag(GPIO1, 18);    
}

void key_init(void)
{
    gpio_cfg cfg;

    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0xF080);

    cfg.direction = GPIO_INPUT;
    cfg.int_mask = GPIO_INT_UNMASKED;
    cfg.int_mode = GPIO_FALLING_EDGE;
    gpio_init(GPIO1, 18, &cfg);

    irq_isr_register(GPIO1_Combined_16_31_IRQn, key_isr, NULL);
    GIC_EnableIRQ(GPIO1_Combined_16_31_IRQn);
}

KEY_STATUS get_key_status(void)
{
    u8 val = 0;

    val = gpio_pin_read(GPIO1, 18);
    if (0 == val) {
        delay_ms(10);
        val = gpio_pin_read(GPIO1, 18);
        if (0 == val) {
            return KEY_PRESSED;
        }
    }

    return KEY_RELEASED;
}