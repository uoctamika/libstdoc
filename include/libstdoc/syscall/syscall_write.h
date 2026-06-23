/*
 * Copyright (C) 2026 Uoc Azizah
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * See the file LICENSE for license details.
 */

#ifndef WRITE_ASM_H
#define WRITE_ASM_H

#include <sys/types.h>

#if defined(__x86_64__)
#define SYS_WRITE write_x86
#elif defined(__i386__)
#define SYS_WRITE write_i686
#elif defined(__arm__)
#define SYS_WRITE write_arm32
#elif defined(__aarch64__)
#define SYS_WRITE write_aarch64
#else
#error "architecture does not support or cannot being detected"
#endif


ssize_t write_x86(int fd, const void *buf, size_t count);
ssize_t write_i686(int fd, const void *buf, size_t count);
ssize_t write_arm32(int fd, const void *buf, size_t count);
ssize_t write_aarch64(int fd, const void *buf, size_t count);

#endif
