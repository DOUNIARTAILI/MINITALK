/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:59:59 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/23 01:42:47 by drtaili          ###   ########.fr       */
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

void    handler()
{
    static int  cpt;
    static char ch;
    int signal1;
    int signal0;
    signal1 = handler_sigusr1();
    signal0 = handler_sigusr2(); 
    ch = 0;
    cpt = 0;
    while (cpt < 8)
    {
        ch = ch << 1;
        if (signal1)
            ch = ch | 1;
        else if(!signal0)
            ch = ch | 0; 
        cpt++;
    }
    if (cpt == 8)
    {
        write(1, ch, 1);
        ch == 0;
    }
}
void    function()
{
    struct sigaction sa_0;
    struct sigaction sa_1;
    sa_0.sa_handler = handler_sigusr2;
    sa_1.sa_handler = handler_sigusr1;
    sigaction(SIGUSR1, &sa_1, NULL);
    sigaction(SIGUSR2, &sa_0, NULL);
}
