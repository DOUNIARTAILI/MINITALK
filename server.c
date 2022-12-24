/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:59:59 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/24 08:14:41 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int	ft_strlenint(long n)
{
	int	i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i + 1);
}

char	*ft_itoa(int n)
{
	int		i;
	char		*a;
	long		nb;

	nb = (long)n;
	i = ft_strlenint(nb);
	a = malloc(ft_strlenint(nb) + 1);
	if (a == NULL)
		return (NULL);
	a[i--] = 0;
	if (nb == 0)
		a[0] = '0';
	if (nb < 0)
	{
		a[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		a[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (a);
}

void    handler(int signum, siginfo_t *info, void *context)
{
    static int cpt;
    static char ch;
	static pid_t pip;

	(void)context;
	if (pip != info->si_pid && info->si_pid != -1)
	{
		ch = 0;
		cpt = 0;
		pip = info->si_pid;
	}
    if (signum == SIGUSR1)
        ch = ch << 1 | 1;
    else if(signum == SIGUSR2)
        ch = ch << 1 | 0; 
    cpt++;
    if (cpt == 8)
    {
        write(1, &ch, 1);
        ch = 0;
        cpt = 0;
    }
}


int main()
{
    struct sigaction sa;
    sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
    write(1, ft_itoa(getpid()), ft_strlenint(getpid()));
	write(1, "\n", 1);
    while (1)
    {
        pause();
    }
    return (0);
}
