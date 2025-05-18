ENTRY(_start)

SECTIONS {
    . = 0x100000;

    /* Read Only Data */
    .driver_rodata : {
        *(.driver_rodata)
    } :ro

    /* Read & Write Data */
    .driver_data : {
        *(.driver_data)
    } :rw

    .text : { *(.text) }
    .data : { *(.data) }
    .bss  : {
        *(.bss)
        *(COMMON)
    }

    /DISCARD/ : { *(.comment) }
}

PHDRS {
    ro PT_LOAD FLAGS(4);  /* PF_R */
    rx PT_LOAD FLAGS(5);  /* PF_R | PF_X */
    rw PT_LOAD FLAGS(6);  /* PF_R | PF_W */
}