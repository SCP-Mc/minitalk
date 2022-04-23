#include "minitalk.h"

int main (int ac, char **av)
{
    char *msg;
    int i;

    i = 0;
    if (ac != 3)
        perror("tal mal ymak!");
    else
    {
        int pid;
        pid = atoi(av[1]);
        if (pid > 0)
        {
            msg = ascii_to_bit(av[2]);
            while (*msg)
            {
                usleep(500);
                if (*msg == '0')
                    kill(pid, SIGUSR1);
                else if (*msg == '1')
                    kill(pid, SIGUSR2);
                msg++;
                if (++i == 0)
                {
                    i = 0;
                    usleep(100);
                }
            }
        }
    }
    return (0);
}