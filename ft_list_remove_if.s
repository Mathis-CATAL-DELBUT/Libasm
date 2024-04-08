section .text
    global ft_list_remove_if ; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
    extern ft_list_size
    extern free

    ;   rdi = t_list **begin_list
    ;   rsi = void *data_ref
    ;   rdx = int (*cmp)()
    ;   rcx = void (*free_fct)(void *)

ft_list_remove_if:
    init:                   ; initialiser les registres
        mov r14, rsi        ; r14 = data_ref
        mov r12, [rdi]      ; r12 = *begin_list 
        mov r13, 0          ; prev NULL 
        jmp remove_if
    
    remove_if:              ; comparer et supprimer si cur->data == data_ref
        cmp r12, 0
        je  exit
        push rdi
        push rdx
        push rcx
        mov rdi, [r12]      ; cur->data
        mov rsi, r14        ; data_ref
        call rdx            ; call cmp function
        pop rcx
        pop rdx
        pop rdi
        cmp rax, 0
        je  remove
        jne  increment

    increment:              ; incrementer les registres si pas besoin de supprimer
        mov r13, r12        ; prev = cur
        mov r12, [r12 + 8]  ; cur = cur->next
        jmp remove_if

    remove:                 ; supprimer l'element 
        cmp r13, 0          ; si prev == NULL alors c'est le premier element
        je  remove_first
        mov r11, [r12 + 8]
        mov [r13 + 8], r11  ; prev->next = cur->next
        push rdi            ; save rdi, rdx, rcx
        push rdx
        push rcx
        mov rdi, [r12]
        call rcx            ; call free function
        pop rcx             ; restore rdi, rdx, rcx
        pop rdx
        pop rdi
        push rdi
        push rdx
        push rcx
        mov r15, [r12 + 8]  ; tmp = cur->next
        mov rdi, r12
        call free           ; free(cur)
        pop rcx
        pop rdx
        pop rdi
        mov r12, r15        ; cur = tmp
        jmp remove_if

    remove_first:           ; supprimer le premier element (meme logique juste on a pas de prev et on avance la tetede la liste)
        mov r8, [r12 + 8]   ; tmp = cur->next
        mov [rdi], r8       ; *begin_list = tmp
        mov r9, r12         ; tmp = cur->data
        mov r12, [r12 + 8]  ; cur = cur->next
        push rdi
        push rdx
        push rcx
        mov rdi, [r9]
        call rcx
        pop rcx
        pop rdx
        pop rdi
        push rdi
        push rdx
        push rcx
        mov rdi, r9
        call free
        pop rcx
        pop rdx
        pop rdi
        jmp remove_if

    exit:
        ret
