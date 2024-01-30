/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:07:28 by nabil             #+#    #+#             */
/*   Updated: 2024/01/21 09:31:56 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int    scan_big(int *stack, int *count)
{
    int     i;
    int     j;
    
    i = 0;
    j = i;
    while(i < *count)
    {
        
        if (stack[i] > stack[j])
        {
            j = i;
            
        }
        i++;
    }
    return(j);
}

int    scan_small(int *stack, int *count)
{
    int     i;
    int     j;
    
    i = 0;
    j = i;
    while(i < *count)
    {
        if (stack[i] < stack[j])
        {
            j = i;
        }
        i++;
    }
    return(j);
}


int     verif_big(int start,int *stack_search, int *count_search)
{
    int     buff;
    
    buff = scan_big(stack_search, count_search);
    if (start >= stack_search[buff])
            return(1);
    return (0);
}

int     verif_small(int start,int *stack_search, int *count_search)
{
    int     buff;
    
    buff = scan_small(stack_search, count_search);
    if (start <= stack_search[buff])
            return(1);
    return (0);
}
