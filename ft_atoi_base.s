section .text
    global ft_atoi_base         ; ft_atoi_base(const char *str --> rdi, const char *base --> rsi) 
    global is_invalid_base
    global check_all_base_characters_loop
    global check_same_characters
    global check_invalid_characters
    global check_len_base
    global increment_whitespaces
    global skip_whitespace
    global increment_sign_positive
    global increment_sign_negative
    global skip_sign
    global result
	global calculate_result
	global error_index
	global find_good_index
	global exit_error
	global exit
    extern ft_strlen

ft_atoi_base: ; base de la fonction 
    push    rbp 
    mov     rbp, rsp
    jmp     is_invalid_base 				; --> is_invalid_base

is_invalid_base:
    mov     r10, rdi						; save str	
    mov     r11, rsi						; save base
    mov     rcx, 0  						; i
    mov     rdx, 0  						; j
    jmp     check_all_base_characters_loop	; --> check_all_base_characters_loop

check_all_base_characters_loop:
    cmp		byte [r11 + rcx], 0				; condition d'arret si str[i] == 0
    je		check_len_base					; si la condition est vraie --> check_len_base
    mov 	rdx, rcx						; j = i
    inc 	rdx								; j = i + 1
    jmp 	check_same_characters			; --> check_same_characters
   
check_same_characters:						
    mov 	al, [r11 + rcx] 				; str[i]
    mov 	bl, [r11 + rdx] 				; str[j]
    cmp 	bl, 0							; condition d'arret si str[j] == 0
    je 		check_invalid_characters		; si la condition est vraie --> check_invalid_characters
    cmp 	al, bl							; str[i] == str[j]
    je 		exit_error						; si la condition est vraie --> exit_error car interdit d'avoir des caracteres identiques
    inc 	rdx								; j++
    jmp 	check_same_characters			; --> check_same_characters

check_invalid_characters:					; verifier si str[i] est un caractere invalide si oui --> exit_error sinon --> check_all_base_characters_loop
    mov  	al, [r11 + rcx]
    cmp  	al, '+'
    je   	exit_error
    cmp  	al, '-'
    je   	exit_error
    cmp  	al, 32
    je   	exit_error
    cmp  	al, 9
    je   	exit_error
    cmp  	al, 10
    je   	exit_error
    cmp  	al, 11
    je   	exit_error
    cmp  	al, 12
    je   	exit_error
    cmp  	al, 13
    je   	exit_error
    inc  	rcx
    jmp  	check_all_base_characters_loop

check_len_base:								; verifier la longueur de la base si elle est inferieur a 2 --> exit_error sinon --> increment_whitespaces
    cmp     rcx, 2
    jl      exit_error
    mov     rcx, 0
    jmp     skip_whitespace

increment_whitespaces:						; incrementer le compteur 
    inc     rcx
    jmp     skip_whitespace

skip_whitespace:							; verifier si str[i] est un espace si oui --> increment_whitespaces sinon --> skip_sign
    cmp     byte [r10 + rcx], 32
    je      increment_whitespaces
    cmp     byte [r10 + rcx], 9
    je      increment_whitespaces
    cmp     byte [r10 + rcx], 10
    je      increment_whitespaces
    cmp     byte [r10 + rcx], 11
    je      increment_whitespaces
    cmp     byte [r10 + rcx], 12
    je      increment_whitespaces
    cmp     byte [r10 + rcx], 13
    je      increment_whitespaces
    mov     r12, 1
    jmp     skip_sign

increment_sign_positive:
    inc     rcx
    jmp     skip_sign

increment_sign_negative:
    inc     rcx
    mov     r12, -1
    jmp     skip_sign

skip_sign:									; verifier si str[i] est un signe si oui --> increment_sign_positive ou increment_sign_negative sinon --> result
    cmp     byte [r10 + rcx], '+'
    je      increment_sign_positive
    cmp     byte [r10 + rcx], '-'
    je      increment_sign_negative
    mov     rdi, r11
    call    ft_strlen
    mov     r13, rax 						; len_base
    mov     rax, 0
    jmp     result

result:										; base de result elle va reset tous les registres necessaires pour le calcul --> check_index
    mov     r14, 0							
    mov     rbx, 0
    mov     rax, 0
    jmp     check_index
            
calculate_result:
    imul    rax, r13						; rax = rax * len_base
    add     rax, r14						; rax = rax + r14 (index)
    mov     r14, 0							; reset index de caractere
    mov     rbx, 0 							; reset compteur pour check_index
    mov     dl, 0							; reset caractere de str	
    mov     sil, 0							; reset caractere de base
    jmp     check_index						; --> check_index

error_index:
    mov    r14, -1
    jmp    exit

find_good_index:
	mov     r14, rbx
    inc     rcx
    jmp     calculate_result

check_index:
    mov     dl, [r11 + rbx]
    mov     sil, [r10 + rcx]
    cmp     dl, 0
    je      error_index						; condition d'arret FINAL si str[index] == 0 --> error_index
    cmp     dl, sil							; Si le caractere correspond au bon index de la base --> find_good_index
    je      find_good_index
    inc     rbx								; Avancer dans la base
    jmp     check_index

exit_error:									; exit avec error ( rax == 0 )
    mov     rax, 0
    leave
    ret

exit:										; exit avec succes ( rax == rax *= r12)
    imul    rax, r12
    leave
    ret