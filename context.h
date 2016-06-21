/**
 * @file context.h
 * @desc 
 *
 * @author James-Adam Renquinha Henri
 */
#ifndef CONTEXT_H
#define CONTEXT_H
//--------------------------------------------------------------------------------------------------
#include <stddef.h>
#include <stdint.h>


struct ctx_t {
    void *(*lr)(void *);
    uint32_t r4, r5, r6, r7, r8, r9, r10, r11, sp;
};

#ifdef __cplusplus
extern "C" {
#endif

void init_ctx(struct ctx_t *init, void *(*fn)(void *), void *stack_bottom, size_t sz);
void *jmp_ctx(struct ctx_t *cur, struct ctx_t *next, void *arg);

#ifdef __cplusplus
}
#endif

//--------------------------------------------------------------------------------------------------
#endif //CONTEXT_H

