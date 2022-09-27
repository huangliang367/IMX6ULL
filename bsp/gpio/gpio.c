#include "imx6ull.h"
#include "gpio.h"

void gpio_init(GPIO_Type *base, int pin, gpio_cfg *cfg)
{
    if (cfg->direction == GPIO_INPUT) {
        base->GDIR &= ~(1 << pin);
    } else {
        base->GDIR |= (1 << pin);
        gpio_pin_write(base, pin, cfg->output);
    }
}

void gpio_pin_write(GPIO_Type *base, int pin, u8 val)
{
    if (0 == val) {
        base->DR &= ~(1 << pin);
    } else {
        base->DR |= (1 << pin);
    }
}

u8 gpio_pin_read(GPIO_Type *base, int pin)
{
    return (base->DR >> pin) & 0x1;
}