#include "context.h"
//--------------------------------------------------------------------------------------------------


void init_ctx(struct ctx_t *init, void *(*fn)(void *), void *stack_bottom, size_t sz) {
    init->lr = fn;
    init->sp = (uint32_t)stack_bottom + sz;
}

/*
    
;void *jmp_ctx(ctx_t *cur, ctx *next, void *arg)
; cur:  r0
; next: r1
; arg:  r2

; version 1: small ctx, big stack
    push {r4-r7, lr}
    mov  r4, r8
    mov  r5, r9
    mov  r6, r10
    mov  r7, r11
    push {r4-r7}
    mov  r3, sp
    str  r3, [r0, #0]

    mov  r0, r2
    ldr  r2, [r1, #0]
    mov  sp, r2
    pop  {r4-r7}
    mov  r4, r8
    mov  r5, r9
    mov  r6, r10
    mov  r7, r11
    pop  {r4-r7, pc}

; version 2: big ctx, small stack
; (the one used)
    mov r3, lr
    stmia r0!, {r3-r7}
    mov  r3, r8
    mov  r4, r9
    mov  r5, r10
    mov  r6, r11
    mov  r7, sp
    stmia r0!, {r3-r7}
    
    mov  r0, r2
    mov  r2, r1
    adds r2, r2, #20
    ldmia r2!, {r3-r7}
    mov r8, r3
    mov r9, r4
    mov r10, r5
    mov r11, r6
    mov sp, r7
    ldmia r1!, {r3-r7}
    bx r3

*/
__attribute__((naked))
void *jmp_ctx(struct ctx_t *cur, struct ctx_t *next, void *arg) {
    asm (
            "mov r3, lr            \n\t"
            "stmia r0!, {r3-r7}    \n\t"
            "mov  r3, r8           \n\t"
            "mov  r4, r9           \n\t"
            "mov  r5, r10          \n\t"
            "mov  r6, r11          \n\t"
            "mov  r7, sp           \n\t"
            "stmia r0!, {r3-r7}    \n\t"

            "mov  r0, r2           \n\t"
            "mov  r2, r1           \n\t"
            "add  r2, r2, #20      \n\t"
            "ldmia r2!, {r3-r7}    \n\t"
            "mov r8, r3            \n\t"
            "mov r9, r4            \n\t"
            "mov r10, r5           \n\t"
            "mov r11, r6           \n\t"
            "mov sp, r7            \n\t"
            "ldmia r1!, {r3-r7}    \n\t"
            "bx r3                 \n\t"
            );
}
