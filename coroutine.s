/*

coroutine *coroutine::create(void (*fn)(void *), void *top_stack = nullptr, size_t size = default_stack_size);

void *coroutine.resume(void *arg)  ::=  void *coroutine_resume(coroutine *, void *arg)

void *coroutine.yield(void *arg)   ::=  void *coroutine_yield(coroutine *, void *arg)
 */

; temp
coroutine_do_save:
    push {r4-r7, lr}
    mov   r4, r8
    mov   r5, r9
    mov   r6, r10
    mov   r7, r11
    push {r4-r7}


    ; Stack:
    ;
    ; Higher addresses: [  LR  ]
    ;                   [  r7  ]
    ;                   [  r6  ]
    ;                   [  r5  ]
    ;                   [  r4  ]
    ;                   [  r11 ]
    ;                   [  r10 ]
    ;                   [  r9  ]
    ;                   [  r8  ] <- sp

    ; r0-r3 preserved.

    ; Switch the stack!

    ; ...


    b coroutine_somewhere?


    ; Resume here!

coroutine_do_resume:
    pop {r0-r7}
    mov r8, r0
    mov r9, r1
    mov r10, r2
    mov r11, r3
    pop {pc}

