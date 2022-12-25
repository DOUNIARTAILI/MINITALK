/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:17:19 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/25 06:00:23 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	r;
	int	i;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * s);
}

void	send(int pip, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (str[i])
	{
		c = 7;
		while (c >= 0)
		{
			if ((str[i] >> c & 1) == 0)
				kill(pip, SIGUSR2);
			else if ((str[i] >> c & 1) == 1)
				kill(pip, SIGUSR1);
			c--;
			usleep(800);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pip;

	if (argc == 3)
	{
		pip = ft_atoi(argv[1]);
		if (pip > 0)
		{
			send(pip, argv[2]);
		}
	}
	return (0);
}
