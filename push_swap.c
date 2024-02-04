/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:08:04 by nabil             #+#    #+#             */
/*   Updated: 2024/02/03 19:38:43 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int    verif(int argc, char **argv)
{
    int     i;
    int     j;

    i = 1;
    j = 1;
    while (argv[i])
    {
        if (argv[i][0] != '-' && !(argv[i][0] <= '9' && argv[i][0] >= '0'))
                    return (0);
        if (ft_atoi(argv[i]) > 2147483747 || ft_atoi(argv[i]) < -2147483648)
                    return (0);
        while (argv[i][j])
        {
            if(!((argv[i][j] <= '9') && (argv[i][j] >= '0')))
                    return(0);
            ++j;
        } 
        j = 1;
        ++i;
    }
    j = 1;
    while (j < argc && argc >= 3)
        {   
            i = j + 1;
            while(argv[i])
            {
                if(ft_strcmp(argv[j], argv[i]) == 0)
                    return(0);
                ++i;
            }      
            ++j;
        }  
    return(1);   
}

void    algo(int *stack_a, int *stack_b, int argc)
{
    int     count_a;
    int     count_b;
    int     best_a = 0;
    int     best_b = 0;
    
    count_b = 0;
    count_a = argc - 1;
    
    if (count_a > 3)
        push_b(stack_a, stack_b, &count_a, &count_b);
    if (count_a > 3)
        push_b(stack_a, stack_b, &count_a, &count_b);
    while(count_a > 3)
    {
        calcule(stack_a, stack_b, count_a, count_b, &best_a, &best_b);  
        push(&best_a, &best_b, stack_a, stack_b, count_a, count_b);
        push_b(stack_a, stack_b, &count_a, &count_b);
        
    }
    three_left(stack_a, count_a);
    while(count_b != 0)
    {
        calcule(stack_b, stack_a, count_b, count_a, &best_b, &best_a);
        push(&best_a, &best_b, stack_a, stack_b, count_a, count_b);
        push_a(stack_a, stack_b, &count_a, &count_b);
        
    }
    best_a = scan_small(stack_a, &count_a);
    push(&best_a, &best_b, stack_a, stack_b, count_a, count_b);
}
  
    

        
int    push_swap(char **argv, int argc)
{
    int     i;
    int     j;
    int *stack_a;
    int *stack_b;

    i = 0;
    j = 1;
    stack_a = (int *)malloc(sizeof(int) * (argc - 1));
    stack_b = (int *)malloc(sizeof(int) * (argc - 1));
    if(!stack_a || !stack_b)
            return(0);
    while(argv[j])
    {
        stack_a[i] = ft_atoi(argv[j]);
        ++i; 
        ++j;
    }
    algo(stack_a, stack_b, argc);
    return(0);
}

int     main(int argc, char **argv)
{
    if (!(argc >= 2))
    {
        ft_printf("Error\n");
        return (0);
    }
    if (verif(argc, argv) == 0)
    {
        ft_printf("Error\n");
        return(0);
    }
    
    push_swap(argv, argc);

}