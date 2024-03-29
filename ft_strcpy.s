section .text
    global ft_strcpy            ; ft_strcpy(char *dest --> rdi, const char *src --> rsi)

ft_strcpy:                  
    push rbp                    ; sauvegarde de la base du pointeur
    mov rbp, rsp                ; rbp pointe sur le debut de la pile

    mov rbx, 0                  ; initialisation du compteur (i)

    .loop:                      ; debut de la boucle
        mov al, [rsi + rbx]     ; al = src[i]
        cmp al, 0               ; si src[i] == 0
        je .end_loop            ; alors on sort de la boucle    
        mov [rdi + rbx], al     ; dest[i] = src[i]
        inc rbx                 ; i++
        jmp .loop               ; on retourne au debut de la boucle

    .end_loop:                  
        mov byte [rdi + rbx], 0 ; dest[i] = 0
        mov rax, rdi            ; rax = dest
        leave                   ; on nettoie la pile === pop rbp
        ret                     ; return rax