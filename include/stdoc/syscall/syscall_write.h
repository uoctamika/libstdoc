#ifndef WRITE_ASM_H
#define WRITE_ASM_H

#include <sys/types.h>


ssize_t write_x86(int fd, const void *buf, size_t count);
ssize_t write_i686(int fd, const void *buf, size_t count);
ssize_t write_arm32(int fd, const void *buf, size_t count);
ssize_t write_aarch64(int fd, const void *buf, size_t count);

#endif
