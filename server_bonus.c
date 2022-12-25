/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:40:34 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/25 06:55:12 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
	}
	if (nb <= 9)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(((nb % 10) + 48));
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int		cpt;
	static char		ch;
	static pid_t	pip;

	(void)context;
	if (pip != info->si_pid && info->si_pid != -1)
	{
		ch = 0;
		cpt = 0;
		pip = info->si_pid;
	}
	if (signum == SIGUSR1)
		ch = ch << 1 | 1;
	else if (signum == SIGUSR2)
		ch = ch << 1 | 0;
	cpt++;
	if (cpt == 8)
	{
		if (ch == 0)
			kill(info->si_pid, SIGUSR2);
		write(1, &ch, 1);
		ch = 0;
		cpt = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
