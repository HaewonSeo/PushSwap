/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:15:55 by haseo             #+#    #+#             */
/*   Updated: 2021/09/23 16:08:02 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long argtoi(char *arg)
{
    int len;
    int sign;
    long long num;

    len = 0;
    if (arg[len] == '+' || arg[len] == '-')
    {
        if (arg[len] == '-')
            sign = -1;
        len++;
    }
    // 0 padding은 고려 안함
    while (arg[len])
    {
        if (!ft_isdigit(arg[len]))
            ft_exit("[Error] Invalid argument\n");
        num = num * 10 + (arg[len++] - '0');
    }
    num *= sign;
    if (len > 11 || num > MAXINT || num < MININT)
        ft_exit("[Error] Invalid argument\n");
    return (num);
}
