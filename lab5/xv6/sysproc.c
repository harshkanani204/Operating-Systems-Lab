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

int sys_v2paddr(void)
{
  addr_t *v_addr , *p_addr;
  if (argptr(0, (void *) &p_addr, sizeof(*p_addr)) < 0)
  {
    cprintf("\tInvalid physical address.\n");
    return -1;
  }
  if (argptr (1, (void *) &v_addr , sizeof(*v_addr)) < 0)
  {
    cprintf("\tInvalid virtual address.\n");
    return -1;
  }

    
  struct proc *currProcess = myproc();

  pde_t *pgdir = currProcess->pgdir;
  pde_t *pde = &pgdir[PDX(v_addr)];


  pde_t *pgtab = (pte_t *)P2V(PTE_ADDR(*pde));  
  pde_t *pte = &pgtab[PTX(v_addr)];              

  if(!(*pte & PTE_P)) {
      cprintf("\tPage table entry not found.\n");
      return -1;  
  }

  if(!(*pte & PTE_U)) {
      cprintf("\tPage table entry can't be accessed.\n");
      return -1;  
  }

  if (!(*pde & PTE_P))
  {
    cprintf("\tPage directory entry not found.\n");
    return -1;
  }
  if(!(*pde & PTE_U)) {
      cprintf("\tPage directory entry can't be accessed.\n");
      return -1;  
  }


  *p_addr = PTE_ADDR(*pte) | PTE_FLAGS(v_addr);

  cprintf("\tVirtual address 0x%x is converted to physical address.\n" , v_addr);
  return 0; 
}