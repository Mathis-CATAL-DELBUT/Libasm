section .text
    global _coucou
    extern printf
    
_coucou:
    lea rdi, coucou_text
    call printf
    ret

section .data
    coucou_text db "coucou", 10
