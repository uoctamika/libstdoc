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

#include <stdarg.h>
#include <stddef.h>
#include <libstdoc/io/stdoc_printf.hxx>

#define PRINTF_BUF_SIZE 1024

static char printf_buf[PRINTF_BUF_SIZE];
static size_t buf_idx = 0;

/* flush buffer ke stdout (fd=1) */
static void flush_buf(void) {
    if (buf_idx > 0) {
        SYS_WRITE(1, printf_buf, buf_idx);
        buf_idx = 0;
    }
}

/* tulis satu karakter ke buffer */
static void buf_putc(char c) {
    if (buf_idx >= PRINTF_BUF_SIZE)
        flush_buf();
    printf_buf[buf_idx++] = c;
}

/* tulis string */
static void buf_puts(const char *s) {
    while (*s)
        buf_putc(*s++);
}

/* tulis unsigned int dalam basis tertentu (2..16) */
static void print_unsigned(unsigned long long n, int base, int uppercase) {
    char tmp[65];  // cukup untuk basis 2 dengan 64 bit
    const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int i = 0;

    if (n == 0) {
        buf_putc('0');
        return;
    }

    while (n > 0) {
        tmp[i++] = digits[n % base];
        n /= base;
    }

    while (i-- > 0)
        buf_putc(tmp[i]);
}

/* tulis signed int */
static void print_signed(long long n) {
    if (n < 0) {
        buf_putc('-');
        n = -n;
    }
    print_unsigned((unsigned long long)n, 10, 0);
}

/* API utama */
int stdoc_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            buf_putc(*format++);
            continue;
        }

        /* karakter setelah '%' */
        format++;
        switch (*format) {
        case 'd':
        case 'i':
            print_signed(va_arg(args, int));
            break;
        case 'u':
            print_unsigned(va_arg(args, unsigned int), 10, 0);
            break;
        case 'x':
            print_unsigned(va_arg(args, unsigned int), 16, 0);
            break;
        case 'X':
            print_unsigned(va_arg(args, unsigned int), 16, 1);
            break;
        case 's': {
            const char *s = va_arg(args, const char*);
            if (!s) s = "(null)";
            buf_puts(s);
            break;
        }
        case 'c':
            buf_putc((char)va_arg(args, int));
            break;
        case 'p': {
            void *p = va_arg(args, void*);
            buf_puts("0x");
            print_unsigned((unsigned long long)p, 16, 0);
            break;
        }
        case '%':
            buf_putc('%');
            break;
        default:
            /* format tidak dikenali: lewatkan */
            buf_putc('%');
            buf_putc(*format);
            break;
        }
        format++;
    }

    va_end(args);
    flush_buf();   /* pastikan semua karakter terkirim */

    /* karena kita belum punya mekanisme pengembalian jumlah karakter,
       untuk sederhana kita kembalikan 0 (sukses). Nanti bisa dikembangkan. */
    return 0;
}

