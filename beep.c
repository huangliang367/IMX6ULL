#include "commont.h"
#include "beep.h"

void beep_init(void)
{
    word32(IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER1) = 0x5;
    word32(IOMUXC_SNVS_SW_PAD_CTL_PAD_SNVS_TAMPER1) = 0x10B0;
    word32(GPIO5_IO01_CFG) = 0x2;
}

void beep_on(void)
{
    unsigned int val = 0;

    val = word32(GPIO5_IO01_IO);
    val &= ~(1 << 1);
    word32(GPIO5_IO01_IO) = val;
}

void beep_off(void)
{
    unsigned int val = 0;
    val = word32(GPIO5_IO01_IO);
    val &= ~(1 << 1);
    val |= (1 << 1);
    word32(GPIO5_IO01_IO) = val;
}
