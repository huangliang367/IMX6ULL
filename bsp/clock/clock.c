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

void imx6ull_clk_init(void)
{
    CCM->CCSR &= ~(1 << 8); //osc_clk(24M)
    CCM->CCSR |= (1 << 2);  //change to step_clk

    CCM_ANALOG->PLL_ARM &= ~(0xFF);
    CCM_ANALOG->PLL_ARM |= 88;
    CCM_ANALOG->PLL_ARM |= (1 << 13);

    CCM->CACRR &= ~(0x7 << 0);
    CCM->CACRR |= 1;
    CCM->CCSR &= ~(1 << 2);
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