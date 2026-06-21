.intel_syntax noprefix

.section .text
.globl write_x86

write_x86:
    mov eax, 1
    syscall
    ret
