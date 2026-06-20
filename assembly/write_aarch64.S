.globl write_aarch64

.type write_aarch64, %function
write_aarch64:
    mov x8, #64
    svc #0
    ret
