section .text
    global start
    global ft_list_size ; ft_list_size(t_list *begin_list --> rdi)

ft_list_size:
    mov rax, 0
    loop:
        cmp rdi, 0
        je return
        inc rax
        mov rdi, [rdi + 8]
        jmp loop

return:
    ret
