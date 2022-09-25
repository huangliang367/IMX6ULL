#include "commont.h"
#include "led.h"

void led_init(void)
{
    unsigned int val = 0;

    word32(IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03) = 0x5;
    word32(IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03) = 0x10B0;
    word32(GPIO1_IO3_CFG) = 0x8;
}

void led_on(void)
{
    unsigned int val = 0;

    val = word32(GPIO1_IO3_IO);
    val &= ~(1 << 3);
    word32(GPIO1_IO3_IO) = val;
}

void led_off(void)
{
    unsigned int val = 0;

    val = word32(GPIO1_IO3_IO);
    val &= ~(1 << 3);
    val |= (1 << 3);
    word32(GPIO1_IO3_IO) = val;
}