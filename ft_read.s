section .text                   ; section de code (3 section disponible : .text = code, .data = variable initialise, .rodata = variable non initialise)
    global ft_read              ; ft_read(int fd --> rdi, void *buf --> rsi, size_t count --> rdx)
    extern __errno_location     ; __errno_location --> fonction externe qui renvoie un pointeur sur errno

ft_read:                        ; fonction ft_read
    push rbp                    ; sauvegarde de la base du pointeur
    mov rbp, rsp                ; rbp pointe sur le debut de la pile

    mov rax, 0                  ; on met 0 dans rax pour preparer le syscall
    syscall                     ; syscall --> appel systeme qui prend en parametre les registres rdi, rsi, rdx passe en argument de la fonction
    cmp rax, 0                  ; on compare le retour de syscall avec 0
    jl  error                   ; si le retour est negatif on va a error

    leave                       ; sinon on nettoie la pile === pop rbp
    ret                         ; on retourne le resultat de syscall dans rax

error:
    neg		rax			        ; on met le resultat de syscall en positif car syscall renvoie un nombre negatif en cas d'erreur  
    mov		rdi, rax            ; on met le resultat de syscall dans rdi en vue de l'appel de __errno_location qui le modifira
	call	__errno_location	; on appelle __errno_location pour modifier errno
	mov		[rax], 	rdi		    ; on met le resultat de syscall dans errno car __errno_location renvoie un pointeur sur errno donc rax == adresse de errno
	mov		rax, -1		        ; on met -1 dans rax pour signaler une erreur
    leave                       ; on nettoie la pile === pop rbp
    ret					        ; return rax
