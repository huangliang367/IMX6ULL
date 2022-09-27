#include "imx6ull.h"
#include "led.h"

void led_init(void)
{
    // func sel
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);
    //IO feature
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10B0);
    //GPIO1_IO03 output
    GPIO1->GDIR |= (1 << 3);
}

void led_on(void)
{
    GPIO1->DR &= ~(1 << 3);
}

void led_off(void)
{
    GPIO1->DR |= (1 << 3);
}