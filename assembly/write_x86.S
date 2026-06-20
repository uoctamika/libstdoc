.intel_syntax noprefix


.globl write_x86

write_x86:
    push ebp
    mov ebp, esp
    mov eax, 4
    mov ebx, [ebp+8]
    mov ecx, [ebp+12]
    mov edx, [ebp+16]
    int 0x80
    pop ebp
    ret
