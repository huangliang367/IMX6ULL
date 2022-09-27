#include "imx6ull.h"
#include "gpio.h"
#include "key.h"
#include "clock.h"

void key_init(void)
{
    gpio_cfg cfg;

    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0xF080);

    cfg.direction = GPIO_INPUT;
    gpio_init(GPIO1, 18, &cfg);
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