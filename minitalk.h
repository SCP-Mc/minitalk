#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>

void    *actual_itoa(char *res, unsigned int nb, int len);
char    *itoa(int n);
void	*ft_loop(char *res, unsigned int nb, int len);
int	    ft_atoi(char *str);
int	    ft_strlen(const char *str);
char    *ascii_to_bit(char *str);
void    get_pid(void);



#endif