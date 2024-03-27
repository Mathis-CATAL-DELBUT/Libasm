; string --> rdi
; return --> rax

section .text
    global ft_strlen

ft_strlen:
    push rbp
    mov rbp, rsp

    mov rsi, 0 ; counter
    .loop:
        mov al , [rdi + rsi]
        cmp al, 0
        je .end_string
        inc rsi
        jmp .loop
    
    .end_string:
        mov rax, rsi
        leave 
    ret