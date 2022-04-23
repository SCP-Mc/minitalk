#include <stdio.h>
#include <stdlib.h>
#include "minitalk.h"

void    fill(char *bits, int bits_i, int val)
{
    int j;

    j = 0;
    while (j < 8)
    {
        if (val % 2 == 0)
            bits[bits_i] = '0';
        else
            bits[bits_i] = '1';
        val /= 2;
        bits_i--;
        j++;
    }
}

char *ascii_to_bit(char *str)
{
    int i; //index of the str
    int bits_i; //index of the bits
    int len; //lenght of the str
    int val;
    char *bits; //the string to which will append the bits

    if (!str)
        return (NULL);
    i = 0;
    bits_i = (i + 1) * 8;
    len = ft_strlen(str);
    bits = calloc(len * 8, sizeof(char));

    while (i < len)
    {
        bits_i = (i + 1) * 8;
        bits_i--;
        val = (int)str[i]; 
        fill(bits, bits_i , val);
        i++;
    }
    return (bits);
}