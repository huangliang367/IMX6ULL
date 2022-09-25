#ifndef _LED_H
#define _LED_H

#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03    0x020E0068
#define IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03    0x020E02F4
#define GPIO1_IO3_CFG                       0x0209C004
#define GPIO1_IO3_IO                        0x0209C000

void led_init(void);
void led_on(void);
void led_off(void);

#endif /* _LED_H */