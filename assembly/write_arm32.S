/*
 * Copyright (C) 2026 Uoc Azizah
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * See the file LICENSE for license details.
 */

#include <libstdoc/syscall/syscall_write.h>

.globl write_arm32

.type write_arm32, %function
write_arm32:
    mov r7, #4
    svc 0
    bx lr
