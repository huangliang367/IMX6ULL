#include "imx6ull.h"
#include "beep.h"

void beep_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0x10B0);

    GPIO5->GDIR |= (1 << 1);
}


void beep_on(void)
{
    GPIO5->DR &= ~(1 << 1);
}

void beep_off(void)
{
    GPIO5->DR |= (1 << 1);
}
