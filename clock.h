#ifndef _CLOCK_H
#define _CLOCK_H

#define CCM_CCGR0   0x020C4068
#define CCM_CCGR1   0x020C406C
#define CCM_CCGR2   0x020C4070
#define CCM_CCGR3   0x020C4074
#define CCM_CCGR4   0x020C4078
#define CCM_CCGR5   0x020C407C
#define CCM_CCGR6   0x020C4080

void clock_enable(void);
void delay_ms(unsigned int ms);

#endif /* _CLOCK_H */