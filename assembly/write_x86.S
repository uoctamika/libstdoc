/*
 * Copyright (C) 2026 Uoc Azizah
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * See the file LICENSE for license details.
 */

#include <libstdoc/syscall/syscall_write.h>

.intel_syntax noprefix

.section .text
.globl write_x86

write_x86:
    mov eax, 1
    syscall
    ret
