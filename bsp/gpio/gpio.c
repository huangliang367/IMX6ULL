#include "imx6ull.h"
#include "gpio.h"

static void gpio_cfg_int(GPIO_Type *base, int pin, gpio_int_mode mode)
{
    if (pin >= 16) {
        base->ICR2 &= ~(0x3 << ((pin - 16) << 1));
        base->ICR2 |= (mode << ((pin - 16) << 1));
    } else {
        base->ICR1 &= ~(0x3 << (pin << 1));
        base->ICR1 |= (mode << (pin << 1));
    }
}

void gpio_clear_int_flag(GPIO_Type *base, unsigned int pin)
{
    base->ISR |= (1 << pin);
}

void gpio_init(GPIO_Type *base, int pin, gpio_cfg *cfg)
{
    if (cfg->direction == GPIO_INPUT) {
        base->GDIR &= ~(1 << pin);
    } else {
        base->GDIR |= (1 << pin);
        gpio_pin_write(base, pin, cfg->output);
    }

    if (cfg->int_mask == GPIO_INT_UNMASKED) {
        switch (cfg->int_mode) {
        case GPIO_LOW_LEVEL:
            gpio_cfg_int(base, pin, GPIO_LOW_LEVEL);
            break;
        case GPIO_HIGH_LEVEL:
            gpio_cfg_int(base, pin, GPIO_HIGH_LEVEL);
            break;
        case GPIO_RISING_EDGE:
            gpio_cfg_int(base, pin, GPIO_RISING_EDGE);
            break;        
        case GPIO_FALLING_EDGE:
            gpio_cfg_int(base, pin, GPIO_FALLING_EDGE);
            break;
        default:
            break;
        }

        base->IMR |= (1 << pin);
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