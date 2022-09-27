#ifndef _LED_H
#define _LED_H

typedef enum {
    LED_ON = 0,
    LED_OFF = 1,
}LED_STATUS;

void led_init(void);
void led_on(void);
void led_off(void);
void led_switch(LED_STATUS status);

#endif /* _LED_H */