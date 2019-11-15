#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

void sys_counter_init(void) {
	counter_init();
}

int sys_counter_get(void) {
	return counter_get();
}

void sys_counter_set(void) {
	int val;
	argint(0, &val);
	counter_set(val);
}

void sys_my_futex_lock(void){
	my_futex_lock();
}

void sys_my_futex_unlock(void){
	my_futex_unlock();
}

void sys_my_spin_lock(void) {
	my_spin_lock();
}

void sys_my_spin_unlock(void) {
	my_spin_unlock();
}

int sys_get_num_yields(void) {
	return get_num_yields();
}

int sys_get_wait_bound(void) {
	return get_wait_bound();
}

void sys_set_wait_bound(void) {
	int val;
	argint(0, &val);
	set_wait_bound(val);
}








