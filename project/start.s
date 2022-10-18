.global _start

_start:
    ldr pc, =reset_handler
    ldr pc, =undefined_handler
    ldr pc, =svc_handler
    ldr pc, =pref_abort_handler
    ldr pc, =data_abort_handler
    ldr pc, =not_used_handler
    ldr pc, =irq_handler
    ldr pc, =fiq_handler

reset_handler:
    cpsid i     /* disable global interrupt */

    /* disable I,DCache MMU */
    mrc p15, 0, r0, c1, c0, 0
    bic r0, r0, #(0x1 << 12)
    bic r0, r0, #(0x1 << 2)
    bic r0, r0, #0x2
    bic r0, r0, #(0x1 << 11)
    bic r0, r0, #0x1
    mcr p15, 0, r0, c1, c0, 0

    /* enter irq mode */
    mrs r0, cpsr
    bic r0, r0, #0x1F
    orr r0, r0, #0x12
    msr cpsr, r0
    ldr sp, =0x8600000

    /* enter SYS mode */
    mrs r0, cpsr
    bic r0, r0, #0x1F
    orr r0, r0, #0x1F
    msr cpsr, r0
    ldr sp, =0x80400000

    /* enter SVC mode */
    mrs r0, cpsr
    bic r0, r0, #0x1F
    orr r0, r0, #0x13
    msr cpsr, r0
    ldr sp, =0x80200000

    cpsie i

    b main
    
undefined_handler:
    ldr r0, undefined_handler
    bx r0

svc_handler:
    ldr r0, svc_handler
    bx r0

pref_abort_handler:
    ldr r0, pref_abort_handler
    bx r0

data_abort_handler:
    ldr r0, data_abort_handler
    bx r0

not_used_handler:
    ldr r0, not_used_handler
    bx r0

irq_handler:
    push {lr}
    push {r0-r3, r12}

    mrs r0, spsr
    push {r0}

    mrc p15, 4, r1, c15, c0, 0
    add r1, r1, #0x2000
    ldr r0, [r1, #0xC]
    push {r0, r1}
    
    cps #0x13
    push {lr}
    ldr r2, =system_irq_handler
    blx r2

    pop {lr}
    cps #0x12
    pop {r0, r1}
    str r0, [r1, #0x10]

    pop {r0}
    msr spsr_cxsf, r0

    pop {r0-r3, r12}
    pop {lr}
    subs pc, lr, #4
    
fiq_handler:
    ldr r0, fiq_handler
    bx r0