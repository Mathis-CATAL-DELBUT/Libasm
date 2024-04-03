section .text
    global ft_list_remove_if ; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
    extern ft_list_size

    ;   rdi = t_list **begin_list
    ;   rsi = void *data_ref
    ;   rdx = int (*cmp)()
    ;   rcx = void (*free_fct)(void *)

ft_list_remove_if:
    init:
        mov r14, rsi
        mov r12, [rdi]
        mov r13, 0
        jmp remove_if
    
    remove_if:
        cmp r12, 0
        je  exit
        push rdi
        push rdx
        push rcx
        mov rdi, [r12]
        mov rsi, r14
        xor rax, rax
        call rdx
        pop rcx
        pop rdx
        pop rdi
        cmp rax, 0
        je  remove
        jne  increment

    increment:
        mov r13, r12
        mov r12, [r12 + 8]
        jmp remove_if

    remove:
        cmp r13, 0
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
        mov r12, [r12 + 8]
        jmp remove_if

    remove_first:
        mov r8, [r12 + 8]
        mov [rdi], r8
        mov r9, [r12]
        mov r12, [r12 + 8]
        push rdi
        push rdx
        push rcx
        mov rdi, [r9]
        call rcx
        pop rcx
        pop rdx
        pop rdi
        jmp remove_if

    exit:
        ret
