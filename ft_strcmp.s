section .text
    global ft_strcmp

ft_strcmp:
    push rbp
    mov rbp, rsp
    .loop:
        mov al, BYTE [rdi]  
        mov bl, BYTE [rsi]
        cmp al, 0
        je .end_loop
        cmp bl, 0
        je .end_loop
        cmp al, bl
        jne .end_loop
        inc rdi
        inc rsi
        jmp .loop

    .end_loop:
        ;movzx rax, al
        ;movzx r10, bl
        ;sub rax, r10
        ;leave
        ;ret
        cmp al, bl
        je .equal
        jg .positive
        jl .negative
        cmp al, 0
        je .negative
        cmp bl, 0
        je .positive


    .positive:
        mov rax, 1
        leave
        ret

    .negative:
        mov rax, -1
        leave
        ret

    .equal:
        mov rax, 0
        leave
        ret
