;rdi first arg -> dest
; rsi second arg -> src

section .text
    global ft_strcmp

ft_strcmp:
    push rbp
    mov rbp, rsp

    mov rcx, 0
    .loop:
        mov al, [rdi + rcx]
        mov bl, [rsi + rcx]
        cmp al, 0
        je .loop_end
        cmp bl, 0
        je .loop_end
        cmp al, bl
        jne .loop_end
        inc rcx
        jmp .loop

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

    .loop_end:
        cmp al, bl
        je .equal
        jg .positive
        jl .negative
        