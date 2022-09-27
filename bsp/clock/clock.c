#include "imx6ull.h"
#include "clock.h"

void clk_enable(void)
{
    CCM->CCGR0 = 0xFFFFFFFF;
    CCM->CCGR1 = 0xFFFFFFFF;
    CCM->CCGR2 = 0xFFFFFFFF;
    CCM->CCGR3 = 0xFFFFFFFF;
    CCM->CCGR4 = 0xFFFFFFFF;
    CCM->CCGR5 = 0xFFFFFFFF;
    CCM->CCGR6 = 0xFFFFFFFF;
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