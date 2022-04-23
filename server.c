#include "minitalk.h"

char    store;

void    get_pid(void)
{
    char *pid;

    pid = itoa(getpid());
    printf("your PID is : %s\n", pid);
    free(pid);
}

void    handler(int sig)
{
    static int  i;

    if (sig == SIGUSR1)
        store = (store << 1) + 0;
    else if (sig == SIGUSR2)
        store = (store << 1) + 1;
    i++;
    if (i == 8)
    {
        write(1, &store, 1);
        i = 0;
        store = 0;
    }
}

int main (void)
{
    get_pid();
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while(1)
    {
        pause ();
    }
}