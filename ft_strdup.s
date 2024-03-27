section .text                       ; section de code (3 section disponible : .text = code, .data = variable initialise, .rodata = variable non initialise)
    global ft_strdup                ; ft_strdup(const char *str --> rdi)
    extern malloc               
    extern ft_strlen

ft_strdup:                          ; ft_strdup(const char *str --> rdi)      
    push rbp                        ; sauvegarde de la base du pointeur
    mov rbp, rsp                    ; rbp pointe sur le debut de la pile


    mov     rbx, rdi                ; rbx = str
    call    ft_strlen               ; rax = len
    mov     r10, rax                ; r10 = len
    add     r10, 1                  ; r10 = len + 1
    mov     rdi, r10                ; rdi = len + 1
    call    malloc                  ; rax = new_str
    mov     rsi, rax                ; rsi = new_str
    mov     rcx, 0                  ; compteur (i)
    .loop:
        mov   al, [rbx + rcx]       ; al = str[i]      
        cmp   al, 0                 ; si str[i] == 0
        mov   byte [rsi + rcx], al  ; new_str[i] = str[i]
        je    .end_loop             ; fin de la boucle
        inc   rcx                   ; i++
        jmp   .loop

    .end_loop:
    mov     byte [rsi + rcx], 0     ; new_str[i] = 0
    mov     rax, rsi                ; rax = new_str
    leave                           ; on nettoie la pile === pop rbp
    ret                             ; on retourne new_str qui est dans rax