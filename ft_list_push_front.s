section .text
    global ft_list_push_front   ; void ft_list_push_front(t_list **begin_list --> rdi, void *data --> rsi);
    extern malloc

ft_list_push_front: 
    push rdi                    ; sauvegarde de rdi pour le restaurer après l'appel à malloc
    push rsi                    ; sauvegarde de rsi pour le restaurer après l'appel à malloc
    mov rdi, 16                 ; 8 octets pour le pointeur vers le prochain élément de la liste et 8 octets pour le pointeur vers la donnée
    call malloc         
    pop rsi                     ; restauration de rsi
    mov qword [rax], rsi        ; stockage de la donnée dans le nouvel élément de la liste
    pop rdi                     ; restauration de rdi
    mov rdx, [rdi]              ; récupération du pointeur vers le premier élément de la liste
    mov qword [rax + 8], rdx    ; stockage du pointeur vers le premier élément dans le next de l'élément nouvellement créé
    mov [rdi], rax              ; stockage du pointeur vers l'élément nouvellement créé dans le pointeur vers le premier élément de la liste
    ret 


    
    
