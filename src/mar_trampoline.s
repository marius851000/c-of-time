.align 4
InitSomeGraphicStuffTrampoline:
    push {r3, lr}

    bl TestCustomLoadWAN

    pop {r3, lr}
    mov r4, #1
    bx lr

.align 4
ObjectRenderHookTrampoline:
    push {lr}

    bl TestCustomRenderWAN

    pop {lr}

    sub sp, sp, #0xc

    bx lr
