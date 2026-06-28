/*
 * Copyright (C) 2026 Uoc Azizah
 *
 * This file is part of libstdoc.
 *
 * libstdoc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * libstdoc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libstdoc. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef WRITE_ASM_HXX
#define WRITE_ASM_HXX

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

#endif /* WRITE_ASM_HXX */
