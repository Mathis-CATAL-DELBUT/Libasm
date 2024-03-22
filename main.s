%define SYS_WRITE 1
%define SYS_EXIT 60
%define FD 1

section .data
    separator_string db "----------------", 10, 0
    separator_string_len equ $ - separator_string
    first_string db "Hello", 10, 0
    first_string_len equ $ - first_string
    format db "Length: %d", 10, 0

section .text
    global _start
    global _main
    global _separator

    extern _coucou
    extern _str_len
    extern printf

_separator:
    mov rax, SYS_WRITE
    mov rdi, FD
    mov rsi, separator_string
    mov rdx, separator_string_len
    syscall
    ret

_start:
    call _main
    mov al, SYS_EXIT
    xor edi, edi
    syscall

_main:
    push rbp
    mov rbp, rsp

    call _coucou
    call _separator

    call _str_len

    ;mov rdi, rax
    ;call printf

    leave
    ret
