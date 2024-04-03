section .text
    global ft_list_sort ; void *ft_list_sort(t_list **begin_list, int (*cmp)());

ft_list_sort:
    init:
        push    rdi             ; Sauvegarde la valeur de begin_list
        mov     rbx, [rdi]      ; rbx = begin_list
        mov     r10, rsi        ; r10 = cmp
        mov     r12, [rdi]      ; r12 = premier maillon
        cmp     r12, 0          ; Si le premier maillon est NULL, on sort
        je      exit
        mov     r13, [r12 + 8]  ; r13 = maillon suivant
        cmp     r13, 0          ; Si le maillon suivant est NULL, on sort
        je      exit            
        jmp     compare         ; Sinon, on compare les deux éléments
    
    start:                      ; Reset les valeurs de r12 et r13 a chaque swap
        mov     r12, rbx        ; r12 = premier maillon
        mov     r13, [rbx + 8]  ; r13 = begin_list
        cmp     r13, 0          ; Si le maillon suivant est NULL, on sort
        je      exit
        jmp     compare         ; Sinon, on compare les deux éléments
    
    compare:
        mov     rdi, [r12]      ; rdi = maillon actuel
        mov     rsi, [r13]      ; rsi = maillon suivant
        call    r10             ; Appel de la fonction de comparaison
        cmp     rax, 1          ; Si rax = 1, on swap
        je      swap            
        jl      else            ; Sinon, on passe au maillon suivant
    
    swap:
        mov     r14, [r13]      ; Sauvegarde la valeur de l'élément suivant de r13 (temporaire)
        mov     r15, [r12]      ; Sauvegarde la valeur de l'élément suivant de r12 (temporaire)
        mov     [r13], r15      ; Met la valeur de r12 dans l'élément suivant de r13
        mov     [r12], r14      ; Met la valeur de r13 dans l'élément suivant de r12
        jmp     start

    
    else:
        mov     r12, [r12 + 8]  ; r12 = maillon suivant
        mov     r13, [r13 + 8]  ; r13 = maillon suivant
        cmp     r13, 0          ; Si le maillon suivant est NULL, on sort
        je      exit
        jmp     compare

exit:
        pop     rdi             ; Restaure la valeur de begin_list
        ret

    