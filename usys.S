#include "syscall.h"
#include "traps.h"

#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
SYSCALL(counter_init)
SYSCALL(counter_get)
SYSCALL(counter_set)
SYSCALL(my_futex_lock)
SYSCALL(my_futex_unlock)
SYSCALL(get_num_yields)
SYSCALL(set_wait_bound)
SYSCALL(get_wait_bound)
SYSCALL(my_spin_lock)
SYSCALL(my_spin_unlock)
