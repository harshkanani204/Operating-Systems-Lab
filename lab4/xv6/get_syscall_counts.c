// made file 
#include "types.h"
#include "user.h"
#include "syscall.h"

int main(int argc, char* argv[])
{
    printf(1, "initial fork count %d\n", getcount(SYS_fork));
    if (fork() == 0) {
        printf(1,"============================FOR CHILD========================\n");
        printf(1, "child fork count %d\n", getcount(SYS_fork));
        printf(1, "child write count %d\n", getcount(SYS_write));
        printf(1,"\n");
        exit();
    } else {
        wait();
        printf(1,"============================FOR PARENT========================\n");
        printf(1, "parent fork count %d\n", getcount(SYS_fork));
        printf(1, "parent write count %d\n", getcount(SYS_write));
        printf(1,"\n");
    }

    printf(1,"============================JUST TO DIFFERENCIATE========================\n");
    printf(1, "Number of Time fork was called: %d\n", getcount(1));
    printf(1, "Number of Time exit was called: %d\n", getcount(2));
    printf(1, "Number of Time wait was called: %d\n", getcount(3));
    printf(1, "Number of Time pipe was called: %d\n", getcount(4));
    printf(1, "Number of Time read was called: %d\n", getcount(5));
    printf(1, "Number of Time kill was called: %d\n", getcount(6));
    printf(1, "Number of Time exec was called: %d\n", getcount(7));
    printf(1, "Number of Time fstat was called: %d\n", getcount(8));
    printf(1, "Number of Time chdir was called: %d\n", getcount(9));
    printf(1, "Number of Time dup was called: %d\n", getcount(10));
    printf(1, "Number of Time getpid was called: %d\n", getcount(11));
    printf(1, "Number of Time sbrk was called: %d\n", getcount(12));
    printf(1, "Number of Time sleep was called: %d\n", getcount(13));
    printf(1, "Number of Time uptime was called: %d\n", getcount(14));
    printf(1, "Number of Time open was called: %d\n", getcount(15));
    printf(1, "Number of Time write was called: %d\n", getcount(16));
    printf(1, "Number of Time mknod was called: %d\n", getcount(17));
    printf(1, "Number of Time unlink was called: %d\n", getcount(18));
    printf(1, "Number of Time link was called: %d\n", getcount(19));
    printf(1, "Number of Time mkdir was called: %d\n", getcount(20));
    printf(1, "Number of Time close was called: %d\n", getcount(21));
    printf(1, "Number of Time getcount was called: %d\n", getcount(22));
    printf(1,"\n");
    exit();
}
