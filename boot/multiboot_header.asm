; multiboot_header.asm

SECTION .multiboot
align 4
; Multiboot header as specified by the multiboot spec
dd 0x1BADB002            ; magic number
dd 0x00                  ; flags
dd -(0x1BADB002+0x00)    ; checksum

SECTION .text
global start
