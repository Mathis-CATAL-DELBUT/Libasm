section .text                   ; section de code (3 section disponible : .text = code, .data = variable initialise, .rodata = variable non initialise)
    global ft_write             ; ft_write(int fd --> rdi, void *buf --> rsi, size_t count --> rdx)
    extern	__errno_location    

ft_write:

    mov rax, 1                  ; syscall write
    syscall                     ; appel systeme pour write qui stocke le code erreur dans rax
    cmp rax, 0                  ; on compare le resultat de syscall avec 0
    jl error                    ; si le resultat est 0 on jump a error
    ret

error:
    neg		rax			        ; on met le resultat de syscall en positif car syscall renvoie un nombre negatif en cas d'erreur  
    mov		rdi, rax            ; on met le resultat de syscall dans rdi en vue de l'appel de __errno_location qui le modifira
	call	__errno_location	; on appelle __errno_location pour modifier errno
	mov		[rax], 	rdi		    ; on met le resultat de syscall dans errno car __errno_location renvoie un pointeur sur errno donc rax == adresse de errno
	mov		rax, -1		        ; on met -1 dans rax pour signaler une erreur
    ret					        ; return rax
