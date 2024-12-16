/* linker.ld */
ENTRY(start)

SECTIONS
{
    /* Start at 1MB for kernel (just a common practice) */
    . = 1M;

    .multiboot :
    {
        *(.multiboot)
    }

    .text :
    {
        *(.text*)
    }

    .rodata :
    {
        *(.rodata*)
    }

    .data :
    {
        *(.data*)
    }

    .bss :
    {
        *(.bss*)
        *(COMMON)
    }

    /DISCARD/ :
    {
        *(*.eh_frame)
        *(*.eh_frame_hdr)
    }
}
