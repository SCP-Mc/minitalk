#include "minitalk.h"

static int length(unsigned int n, int len)
{
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return (len);
}

static void *actual_itoa(char *res, unsigned int nb, int len)
{
    while (nb > 0)
    {
        res[--len] = ((nb % 10) + '0');
        nb /= 10;
    }
    return (res);
}

char *itoa(int n)
{
    int         len;
    unsigned int nb;
    char        *res;

    len = 0;
    nb = n;
    if(n < 0)
    {
        len = 1;
        nb = -(unsigned int)n; 
    }
    len = length(n, len);
    if (n == 0)
        len = 1;
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (!(res))
        return (NULL);
    if (n == 0)
        res[0] = '0';
    res[len] = '\0';
    if (nb > 0)
        res = actual_itoa(res, nb, len);
    if (n < 0)
        res[0] = '-';
    return (res);
}
