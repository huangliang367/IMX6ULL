#include "int.h"

static unsigned int irq_int_nest = 0;

static irq_isr_t irq_table[NUMBER_OF_INT_VECTORS];

static void default_irq_isr(unsigned int gicciar, void *param)
{
    while (1) {

    }
}

void irq_table_init(void)
{
    int i = 0;
    for (i = 0; i < NUMBER_OF_INT_VECTORS; i++) {
        irq_table[i].isr = default_irq_isr;
        irq_table[i].param = NULL;
    }
}

void int_init(void)
{
    GIC_Init();

    __set_VBAR(0x87800000);     /* 中断向量表基地址 */

    irq_table_init();

    irq_int_nest = 0;
}

void system_irq_handler(unsigned int gicciar)
{
    uint32_t int_num = gicciar & 0x3FF;

    if ((int_num == 1023) || (int_num >= NUMBER_OF_INT_VECTORS)) {
        return;
    }

    irq_int_nest++;
    irq_table[int_num].isr(int_num, irq_table[int_num].param);
    irq_int_nest--;
}

void irq_isr_register(IRQn_Type irq, iqr_isr isr, void *param)
{
    if (irq < NUMBER_OF_INT_VECTORS) {
        irq_table[irq].isr = isr;
        irq_table[irq].param = param;
    }
}