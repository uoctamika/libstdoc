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
