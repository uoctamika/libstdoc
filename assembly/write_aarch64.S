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

.globl write_aarch64

.type write_aarch64, %function
write_aarch64:
    mov x8, #64
    svc #0
    ret
