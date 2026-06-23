/*
 * Copyright (C) 2026 Uoc Azizah
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * See the file LICENSE for license details.
 */

#ifndef STDOC_PRINTF_H
#define STDOC_PRINTF_H

#include <libstdoc/syscall/syscall_write.h>

int stdoc_printf(const char *format, ...);

#endif /* STDOC_PRINTF_H */
