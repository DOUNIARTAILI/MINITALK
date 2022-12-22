/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:17:19 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/22 05:41:19 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

// main.c 4322 "je suis client" j = 10001110 
//                                  1          j >> 7 => 0000000|1| && 1 = 1 sigusr1
//                                   0         j >> 6 => 0000000|0| && 1 = 0 sigusr2
//                                    0        j >> 5 => 0000000|0| && 1 = 0 sigusr2
void send(char *str, int pip)
{
    int i;
    int c;
    int res;
    i = 0;
    while(str != NULL)
    {
        c = 7;
        while(c > 0)
        {
            res = 0;
            str[i] >> c;
            res = (str[i] >> c) && 1;
            if (res == 0)
                kill(pip, SIGUSR2);
            else if (res == 1)
                kill(pip, SIGUSR1);
            c--;
        }
        i++;
    }
}
int main(int argc, char *argv[])
{
    int res;
    while(argc == 3)
    {
        while (argv[1] >= 0)
        {
            function(argv[2], argv[1]);
        }
    } 
}