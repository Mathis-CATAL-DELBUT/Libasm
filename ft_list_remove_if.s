section .text
    global ft_list_remove_if ; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
    extern ft_list_size
    extern free

    ;   rdi = t_list **begin_list
    ;   rsi = void *data_ref
    ;   rdx = int (*cmp)()
    ;   rcx = void (*free_fct)(void *)

ft_list_remove_if:
    init:
        mov r14, rsi      ; r14 = data_ref
        mov r12, [rdi]    ; r12 = *begin_list 
        mov r13, 0 ; prev NULL 
        jmp remove_if
    
    remove_if:
        cmp r12, 0
        je  exit
        push rdi
        push rdx
        push rcx
        mov rdi, [r12] ; cur->data
        mov rsi, r14 ; data_ref
        call rdx ; call cmp function
        pop rcx
        pop rdx
        pop rdi
        cmp rax, 0
        je  remove
        jne  increment

    increment:
        mov r13, r12 ; prev = cur
        mov r12, [r12 + 8] ; cur = cur->next
        jmp remove_if

    remove:
        cmp r13, 0 ; prev not set first element case
        je  remove_first
        mov r11, [r12 + 8]
        mov [r13 + 8], r11
        push rdi
        push rdx
        push rcx
        mov rdi, [r12]
        call rcx
        pop rcx
        pop rdx
        pop rdi
        push rdi
        push rdx
        push rcx
        mov rdi, r12
        call free
        pop rcx
        pop rdx
        pop rdi
        mov r12, [r12 + 8]
        jmp remove_if

    remove_first:
        mov r8, [r12 + 8] ; tmp = cur->next
        mov [rdi], r8 ; *begin_list = tmp
        mov r9, r12 ; tmp = cur->data
        mov r12, [r12 + 8] ; 
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
