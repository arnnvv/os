; boot/boot_entry.asm
[bits 32]
global start
extern kernel_main

start:
    call kernel_main

hang:
    hlt
    jmp hang
