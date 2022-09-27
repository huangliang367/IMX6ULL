#ifndef _BEEP_H
#define _BEEP_H

typedef enum {
    BEEP_ON = 0,
    BEEP_OFF = 1,
}BEEP_STATUS;

void beep_init(void);
void beep_on(void);
void beep_off(void);
void beep_switch(BEEP_STATUS status);

#endif /* _BEEP_H */