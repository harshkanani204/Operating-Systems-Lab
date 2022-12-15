#include "types.h"
#include "user.h"
#include "syscall.h"
#include "memlayout.h"
void getResults (addr_t *v_addr)
{
    addr_t p_addr;
    printf(1, "\tConverting Virtual Address : 0x%x\n", v_addr);
    int status= v2paddr(&p_addr , v_addr);
    if (status == 0)
    {
        printf(1, "\tPhysical Address Obtained: 0x%x\n", p_addr);
    }
    printf(1 , "\n");
}
int Test3 = 6969;
int main(int argc, char *argv[]) {
    printf(1, "\t\t****Testing v2paddr****\n\n");

    int Test1 = 0 ;
    addr_t* v_addr = (addr_t*)(&Test1);
    getResults(v_addr);

    addr_t* Test2 = (void*)(KERNBASE + 0x69); 
    v_addr = Test2;
    getResults(v_addr);

    v_addr = (addr_t*)(&Test3);
    getResults(v_addr);
    exit();
}