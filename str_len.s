; Take a string in rdi register
; Print its length and return len in rax register

section .text
    global _str_len
    extern printf

_str_len:
    push rbp
    mov rbp, rsp

    mov rsi, 0
    .loop
        mov al , [rdi + rsi]
        cmp al, 0
        je .end_string
        inc rsi
        jmp .loop
    
    .end_string:
        mov rax, rsi
        mov rdi, format 
        call printf 
        leave 
    ret

section .data
    format db "Length: %d", 10