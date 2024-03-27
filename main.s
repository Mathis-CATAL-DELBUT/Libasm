%define SYS_WRITE 1
%define SYS_EXIT 60
%define FD 1

section .text
    global _start
    global _main
    global _separator
    global _call_ft_strlen
    global _call_ft_strcpy

    extern ft_strlen
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

_call_ft_strlen:
    push rbp
    mov rbp, rsp

    mov rdi, ft_strlen_string
    call printf

    lea rdi, [first_string]
    call ft_strlen

    mov rdi, format
    mov rsi, rbx
    call printf

    leave
    ret

_call_ft_strcpy:
    push rbp
    mov rbp, rsp

    mov rdi, ft_strcpy_string
    call printf

    lea rdi, [first_string]
    xor rsi, rsi
    ;call ft_strcpy

    mov rdi, format
    mov rsi, rbx
    call printf

    leave
    ret

_main:
    push rbp
    mov rbp, rsp

    call _separator
    call _call_ft_strlen
    call _separator

    leave

    ret

section .data
    separator_string db "----------------", 10, 0
    separator_string_len equ $ - separator_string
    first_string db "For tests", 10, 0
    first_string_len equ $ - first_string
    format db "Length: %d", 10, 0

    ft_strlen_string db "ft_strlen :", 10, 10, 0
    ft_strcpy_string db "ft_strcpy :", 10, 10, 0