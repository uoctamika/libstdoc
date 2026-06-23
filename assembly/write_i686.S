/*
 * Copyright (C) 2026 Uoc Azizah
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * See the file LICENSE for license details.
 */

#include <libstdoc/syscall/syscall_write.h>

.intel_syntax noprefix


.globl write_i686

write_i686:
    push ebp
    mov ebp, esp
    mov eax, 4
    mov ebx, [ebp+8]
    mov ecx, [ebp+12]
    mov edx, [ebp+16]
    int 0x80
    pop ebp
    ret
