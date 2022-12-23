/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:59:59 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/23 02:00:54 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

int handler_sigusr2()
{
    return (0);
}

int handler_sigusr1()
{
    return (1);
}

void    handler(int signum)
{
    static int  cpt;
    static char ch;
    ch = 0;
    cpt = 0;
    if (signum == SIGUSR1)
        ch = (ch << 1) | 1;
    else if(signum == SIGUSR2)
        ch = (ch << 1) | 0; 
    cpt++;
    if (cpt == 8)
    {
        write(1, ch, 1);
        ch = 0;
        cpt = 0;
    }
}
void    function()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}
