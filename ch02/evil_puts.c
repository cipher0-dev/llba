#include <sys/syscall.h>

int _write(int fd, void *buf, int count) {
  long ret;

  // perform write syscall
  __asm__ __volatile__(
      "pushl %%ebx\n\t"       // save callee saved ebx on stack
      "movl %%esi, %%ebx\n\t" // mov esi into ebx for fd syscall arg
      "int $0x80\n\t"         // make syscall
      "popl %%ebx\n\t"        // restore callee saved ebx from stack
      : "=a"(ret)             // use eax for ret val
      : "0"(SYS_write),       // store syscall num in eax
        "S"((long)fd),        // the first arg gets stored in esi because ebx is
                              // callee saved and would otherwise be clobbered
        "c"((long)buf),       // store second arg in ecx
        "d"((long)count));    // store third arg in edx
  if (ret >= 0)
    return (int)ret;

  return -1;
}

int evil_puts(void) {
  _write(1, "HAHA puts() has been hijacked!\n", 31);
  return 1;
}
