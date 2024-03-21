section .data
    first_string db "Hello", 10

section .text
    global _start
    global _main
    extern _coucou
    extern _str_len

_start:
    call _main
    mov al, 60
    xor edi, edi
    syscall


_main:
    call _coucou
    ret
