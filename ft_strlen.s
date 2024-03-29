section .text                   ; section de code (3 section disponible : .text = code, .data = variable initialise, .rodata = variable non initialise)
    global ft_strlen            ; ft_strlen(char *str --> rdi)

ft_strlen:
    push rbp                    ; sauvegarde de la base du pointeur
    mov rbp, rsp                ; rbp pointe sur le debut de la pile

    mov rsi, 0                  ; initialisation du compteur de caractere (i)
    .loop:
        mov al , [rdi + rsi]    ; al = str[i]
        cmp al, 0               ; si str[i] == 0
        je .end_string          ; alors on sort de la boucle
        inc rsi                 ; i++
        jmp .loop

    .end_string:
        mov rax, rsi            ; rax = i
        leave                   ; on nettoie la pile === pop rbp
        ret