.intel_syntax noprefix
.global outw, inw

outw:
    mov dx, di
    mov ax, si
    out dx, ax
    ret

inw:
    mov dx, di
    in ax, dx
    ret