section .text
    global ft_list_sort ; void *ft_list_sort(t_list **begin_list, int (*cmp)());

// boucle infinie !!!!!!!!!!!!!!!
ft_list_sort:
    init:
        push    rdi
        mov     rbx, [rdi] ; rbx = begin_list
        mov     r10, rsi    ; r10 = cmp
        mov     r11, [rdi]  ; r11 = premier maillon
        mov     r12, [r11 + 8]  ; r12 = maillon suivant
        cmp     r12, 0
        je      exit
        jmp     compare
    start:
        xor     r11, r11
        xor     r12, r12
        mov     r11, rbx  ; r11 = premier maillon
        mov     r12, [rbx + 8]  ; r12 = begin_list
        cmp     r12, 0
        je      exit
        jmp     compare
    compare:
        mov     rdi, [r11]
        mov     rsi, [r12]
        call    r10
        cmp     rax, 0
        je      swap
        jle     else
    swap:
        mov     r13, [r12]     ; Sauvegarde la valeur de l'élément suivant de r12 (temporaire)
        mov     r14, [r11]     ; Sauvegarde la valeur de l'élément suivant de r11 (temporaire)
        mov     [r12], r14     ; Met la valeur de r11 dans l'élément suivant de r12
        mov     [r11], r13     ; Met la valeur de r12 dans l'élément suivant de r11
        ;mov     r11, [r11 + 8] ; Avance au prochain élément dans la liste 1
        ;mov     r12, [r12 + 8] ; Avance au prochain élément dans la liste 2
        ;cmp     r12, 0
        ;je      exit
        jmp     start

    else:
        mov     r11, [r11 + 8] ; r11 = maillon suivant
        mov     r12, [r12 + 8] ; r12 = maillon suivant
        cmp     r12, 0
        je      exit
        jmp     compare

exit:
        pop     rdi
        ret

    