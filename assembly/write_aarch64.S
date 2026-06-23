/*
 * Copyright (C) 2026 Uoc Azizah
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * See the file LICENSE for license details.
 */

#include <libstdoc/syscall/syscall_write.h>

.globl write_aarch64

.type write_aarch64, %function
write_aarch64:
    mov x8, #64
    svc #0
    ret
