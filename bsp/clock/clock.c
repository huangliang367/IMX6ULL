#include "commont.h"
#include "clock.h"

void clock_enable(void)
{
    word32(CCM_CCGR0) = 0xFFFFFFFF;
    word32(CCM_CCGR1) = 0xFFFFFFFF;
    word32(CCM_CCGR2) = 0xFFFFFFFF;
    word32(CCM_CCGR3) = 0xFFFFFFFF;
    word32(CCM_CCGR4) = 0xFFFFFFFF;
    word32(CCM_CCGR5) = 0xFFFFFFFF;
    word32(CCM_CCGR6) = 0xFFFFFFFF;
}

void delay_1ms(void)
{
    volatile unsigned int n = 0x7ff;

    while (n--);
}

void delay_ms(unsigned int ms)
{
    volatile unsigned int n = ms;

    while (n--)
    {
        delay_1ms();
    }
}