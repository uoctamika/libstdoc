.globl write_arm32

.type write_arm32, %function
write_arm32:
    mov r7, #4
    svc 0
    bx lr
