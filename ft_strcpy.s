; dest --> rdi register and src --> rsi register
; reurn --> rax register

section .text
    global ft_strcpy

ft_strcpy:
    push rbp
    mov rbp, rsp

    mov rbx, 0 ; compteur

    .loop:
        mov al, [rsi + rbx]
        cmp al, 0
        je .end_loop
        mov dl, al
        mov [rdi + rbx], dl
        inc rbx
        jmp .loop

    .end_loop:
        mov byte [rdi + rbx], 0
        mov rax, rdi
        leave
        ret