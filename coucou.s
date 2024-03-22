section .text
    global _coucou
    extern printf
    
_coucou:
    push rbp
    mov rbp, rsp

    lea rdi, [rel coucou_text]  
    call printf  

    leave             
    ret

section .data
    coucou_text db "coucou", 10, 0 