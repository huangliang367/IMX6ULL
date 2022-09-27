#ifndef _GPIO_H
#define _GPIO_H

typedef enum {
    GPIO_INPUT = 0,
    GPIO_OUTPUT = 1,
}GPIO_DIRECTION;

typedef struct {
    GPIO_DIRECTION direction;
    u8 output;
}gpio_cfg;

void gpio_init(GPIO_Type *base, int pin, gpio_cfg *cfg);
void gpio_pin_write(GPIO_Type *base, int pin, u8 val);
u8 gpio_pin_read(GPIO_Type *base, int pin);

#endif /* _GPIO_H */