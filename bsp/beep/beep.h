#ifndef _BEEP_H
#define _BEEP_H

#define IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER1     0x0229000C
#define IOMUXC_SNVS_SW_PAD_CTL_PAD_SNVS_TAMPER1     0x02290050
#define GPIO5_IO01_CFG                              0x020AC004
#define GPIO5_IO01_IO                               0x020AC000

void beep_init(void);
void beep_on(void);
void beep_off(void);

#endif /* _BEEP_H */