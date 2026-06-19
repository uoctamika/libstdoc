#ifndef SYS_WRITE_H
#define SYS_WRITE_H

#include <stddef.h>

static inline long write_x86(int fd, const char *buf, size_t count) {
    long ret;
    __asm__ volatile (
        "int $0x80"
        : "=a" (ret)
        : "a" (4), "b" (fd), "c" (buf), "d" (count)
        : "memory"
    );
    return ret;
}

static inline long write_i686(int fd, const char *buf, size_t count) {
    long ret;
    __asm__ volatile (
        "int $0x80"
        : "=a" (ret)
        : "a" (4), "b" (fd), "c" (buf), "d" (count)
        : "memory"
    );
    return ret;
}

static inline long write_arm32(int fd, const char *buf, size_t count) {
    long ret;
    register long syscall_no asm("r7") = 4;
    register long arg0 asm("r0") = fd;
    register const char *arg1 asm("r1") = buf;
    register size_t arg2 asm("r2") = count;
    __asm__ volatile (
        "svc #0"
        : "=r" (arg0)
        : "r" (arg0), "r" (arg1), "r" (arg2), "r" (syscall_no)
        : "memory", "r1", "r2", "r7"
    );
    return arg0;
}

static inline long write_aarch64(int fd, const char *buf, size_t count) {
    long ret;
    register long syscall_no asm("x8") = 64;
    register long arg0 asm("x0") = fd;
    register const char *arg1 asm("x1") = buf;
    register size_t arg2 asm("x2") = count;
    __asm__ volatile (
        "svc #0"
        : "=r" (arg0)
        : "r" (arg0), "r" (arg1), "r" (arg2), "r" (syscall_no)
        : "memory", "x1", "x2", "x8"
    );
    return arg0;
}

#endif  /* SYS_WRITE_H */
