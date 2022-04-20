#include "minitalk.h"

void    get_pid(void)
{
    char *pid;

    pid = itoa(getpid());
    printf("your PID is : %s\n", pid);
    free(pid);
}


int main (void)
{ 
    while(1)
    {
        get_pid();
        sleep(5);
    }
}