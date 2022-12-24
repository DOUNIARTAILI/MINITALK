/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:17:19 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/24 05:06:35 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// main.c 4322 "je suis client" j = 10001110 
//                                  1          j >> 7 => 0000000|1| && 1 = 1 sigusr1
//                                   0         j >> 6 => 0000000|0| && 1 = 0 sigusr2
//                                    0        j >> 5 => 0000000|0| && 1 = 0 sigusr2
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

void send(char *str, int pip)
{
    int i;
    int c;
    i = 0;
    while(str[i])
    {
        c = 7;
        while(c >= 0)
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
int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        if (ft_atoi(argv[1]) >= 0)
        {
            send(argv[2], ft_atoi(argv[1]));
        }
    }
    return (0);
}