#ifndef _INT_H
#define _INT_H
#include "imx6ull.h"

typedef void (*iqr_isr)(unsigned int gicciar, void *param);
typedef struct {
    iqr_isr isr;
    void *param;
}irq_isr_t;

void system_irq_handler(unsigned int gicciar);
void int_init(void);
void irq_isr_register(IRQn_Type irq, iqr_isr isr, void *param);

#endif /* _INT_H */