#ifndef _GPIO_H
#define _GPIO_H

typedef enum {
    GPIO_INPUT = 0,
    GPIO_OUTPUT = 1,
}GPIO_DIRECTION;

typedef enum {
    GPIO_LOW_LEVEL = 0,
    GPIO_HIGH_LEVEL,
    GPIO_RISING_EDGE,
    GPIO_FALLING_EDGE,
}gpio_int_mode;

typedef enum {
    GPIO_INT_MASKED = 0,
    GPIO_INT_UNMASKED,
}gpio_int_mask;

typedef struct {
    GPIO_DIRECTION direction;
    u8 output;
    gpio_int_mode int_mode;
    gpio_int_mask int_mask;
}gpio_cfg;

void gpio_init(GPIO_Type *base, int pin, gpio_cfg *cfg);
void gpio_pin_write(GPIO_Type *base, int pin, u8 val);
u8 gpio_pin_read(GPIO_Type *base, int pin);
void gpio_clear_int_flag(GPIO_Type *base, unsigned int pin);

#endif /* _GPIO_H */