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
        cmp r12, 0
        je  exit
        mov r13, [r12 + 8]
        jmp remove_if
    
    remove_if:
        push rdi
        push rdx
        push rcx
        mov rdi, [r13]
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
        mov r12, r13
        mov r13, [r13 + 8]
        cmp r13, 0
        je  exit
        jmp remove_if

    remove:
        mov r11, [r13 + 8]
        mov [r12 + 8], r11
        push rdi
        push rdx
        push rcx
        mov rdi, r13
        call rcx
        pop rcx
        pop rdx
        pop rdi
        mov r13, [r13 + 8]
        cmp r13, 0
        je  exit
        jmp remove_if

    ;only_one:
        ;mov r12, [rdi]
        ;push rdi
        ;push rdx
        ;push rcx
        ;mov rdi, r13
        ;mov rsi, r14
        ;call rdx
        ;pop rcx
        ;pop rdx
        ;pop rdi
        ;cmp rax, 0
        ;je  remove

    exit:
        ret
