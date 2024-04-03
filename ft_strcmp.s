section .text               ; section de code (3 section disponible : .text = code, .data = variable initialise, .rodata = variable non initialise)
    global ft_strcmp        ; ft_strcmp(const char *s1 --> rdi, const char *s2 --> rsi)

ft_strcmp:                  ; fonction ft_strcmp
    push rbp                ; sauvegarde de la base du pointeur
    mov rbp, rsp            ; rbp pointe sur le debut de la pile

    .loop:                  ; debut de la boucle
        mov al, byte [rdi]  ; al = rdi qui pointe sur le debut de la chaine de caractere (byte = 1 octet)
        mov bl, byte [rsi]  ; bl = rsi qui pointe sur le debut de la chaine de caractere (byte = 1 octet)
        cmp al, 0           ; compare al a 0
        je .end_loop        ; si al = 0 alors aller a .end_loop
        cmp bl, 0           ; compare bl a 0
        je .end_loop        ; si bl = 0 alors aller a .end_loop
        cmp al, bl          ; compare al a bl
        jne .end_loop       ; si al != bl alors aller a .end_loop
        inc rdi             ; incrementation de rdi
        inc rsi             ; incrementation de rsi
        jmp .loop           ; retour a .loop

    .end_loop:
        cmp al, bl          ; compare al a bl
        je .equal           ; si al = bl alors aller a .equal
        jg .positive        ; si al > bl alors aller a .positive
        jl .negative        ; si al < bl alors aller a .negative
        cmp al, 0           ; compare al a 0
        je .negative        ; si al = 0 alors aller a .negative
        cmp bl, 0           ; compare bl a 0
        je .positive        ; si bl = 0 alors aller a .positive


    .positive:              
        mov rax, 1          ; rax = 1
        leave               ; on nettoie la pile === pop rbp
        ret                 ; on retourne la valeur de rax

    .negative:
        mov rax, -1         ; rax = -1
        leave               ; on nettoie la pile === pop rbp
        ret                 ; on retourne la valeur de rax

    .equal:
        mov rax, 0          ; rax = 0
        leave               ; on nettoie la pile === pop rbp
        ret                 ; on retourne la valeur de rax
