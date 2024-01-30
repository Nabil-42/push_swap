/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:39:32 by nabil             #+#    #+#             */
/*   Updated: 2024/01/21 09:40:37 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void    organise_a(int *stack, int *count_a)
{
    int     i;

    i = 0;
    while(i < *count_a)
    {
        stack[i] = stack[i + 1];
        ++i;
    }
}

void    organise_b(int *stack, int *count_b)
{
    int     i;
    
    i = 0;
    while(i < *count_b)
    {
        stack[i] = stack[i + 1];
        ++i;
    }

}

void     swap_a(int  *stack)
{
    int     i;
    int     *buff;
    
    buff = (int *)malloc(sizeof(int));
    i = 0;
    buff[i] = stack[i];
    stack[i] = stack[i + 1];
    stack[i + 1] = buff[i];
    free(buff);
    printf("SWAP A\n");
}    

void     swap_b(int  *stack)
{
    int     i;
    int     *buff;
    
    buff = (int *)malloc(sizeof(int));
    i = 0;
    buff[i] = stack[i];
    stack[i] = stack[i + 1];
    stack[i + 1] = buff[i];
    free(buff);
    ft_printf("SWAP B\n");
}

void     swap_ss(int  *stack_a, int *stack_b)
{
    int     i;
    int     *buff;
    
    buff = (int *)malloc(sizeof(int));
    i = 0;
    buff[i] = stack_a[i];
    stack_a[i] = stack_a[i + 1];
    stack_a[i + 1] = buff[i];
    buff[i] = stack_b[i];
    stack_b[i] = stack_b[i + 1];
    stack_b[i + 1] = buff[i];      
    free(buff);
    ft_printf("SWAP SS\n");
}

void    push_a(int *stack_a, int *stack_b, int *count_a, int *count_b)
{
    int     buff;

    buff = *count_a;
    while(buff >= 0)
    {
        stack_a[buff + 1] = stack_a[buff];
        --buff;
    }
    stack_a[0] = stack_b[0];
    *count_a += 1;
    *count_b -= 1;
    organise_b(stack_b, count_b);
    ft_printf("PUSH A\n");
}

void    push_b(int *stack_a, int *stack_b, int *count_a, int *count_b)
{
    int     buff;

    buff = *count_b;
    while(buff >= 0)
    {
        stack_b[buff + 1] = stack_b[buff];
        --buff;
    }
    stack_b[0] = stack_a[0];
    *count_b += 1;
    *count_a -= 1;
    organise_a(stack_a, count_a);
    ft_printf("PUSH B\n");
}

void    rotate_a(int *stack_a, int *count_a, int *best_a)
{
    int buff;

    buff = *count_a;
    stack_a[buff] = stack_a[0];
    organise_a(stack_a, count_a);
    *best_a -= 1;
    printf("ROTATE A\n");
}

void    rotate_b(int *stack_b, int *count_b, int *best_b)
{
    int buff;

    buff = *count_b;
    stack_b[buff] = stack_b[0];
    organise_b(stack_b, count_b);
    // ft_printf("rotate B \n");
    *best_b -= 1;
    printf("ROTATE B\n");
}

void    rotate_double(int *stack_a, int *count_a, int *stack_b, int *count_b, int *best_a, int *best_b)
{
   int buff;

    buff = *count_a;
    stack_a[buff] = stack_a[0];
    organise_a(stack_a, count_a);
    *best_a -= 1;
    buff = *count_b;
    stack_b[buff] = stack_b[0];
    organise_b(stack_b, count_b);
    // ft_printf("rotate B \n");
    *best_b -= 1;
    printf("ROTATE DOUBLE\n");
}

void    revers_rotate_a(int *stack_a, int *count_a, int *best_a)
{
    int     buff;
    int     storage;
    
    buff = *count_a;
    storage = stack_a[buff - 1];
    while(buff > 0)
    {
        stack_a[buff] = stack_a[buff - 1];
        --buff;
    }
    stack_a[buff] = storage;
    *best_a += 1;
    printf("REVERS ROTATE A\n");
}

void    revers_rotate_b(int *stack_b, int *count_b, int *best_b) 
{
    int     buff;
    int     storage;
    
    buff = *count_b;
    storage = stack_b[buff - 1];
    while(buff > 0)
    {
        stack_b[buff] = stack_b[buff - 1];
        --buff;
    }
    stack_b[buff] = storage;
    *best_b += 1;
    printf("REVERS ROTATE B\n");
}

void    revers_rotate_double(int *stack_a, int *count_a, int *stack_b, int *count_b,  int *best_a, int *best_b)
{
    int     buff;
    int     storage;
    
    buff = *count_a;
    storage = stack_a[buff - 1];
    while(buff > 0)
    {
        stack_a[buff] = stack_a[buff - 1];
        --buff;
    }
    stack_a[buff] = storage;
    *best_a += 1;
    buff = *count_b;
    storage = stack_b[buff - 1];
    while(buff > 0)
    {
        stack_b[buff] = stack_b[buff - 1];
        --buff;
    }
    stack_b[buff] = storage;
    *best_b += 1;
    printf("REVERS ROTATE DOUBLE\n");
}

