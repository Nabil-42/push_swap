/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:39:32 by nabil             #+#    #+#             */
/*   Updated: 2024/02/03 12:14:52 by nabil            ###   ########.fr       */
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
    ft_printf("sa\n");
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
    ft_printf("sb\n");
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
    ft_printf("ss\n");
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
    ft_printf("pa\n");
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
    ft_printf("pb\n");
}

void    rotate_a(int *stack_a, int *count_a, int *best_a)
{
    int buff;

    buff = *count_a;
    stack_a[buff] = stack_a[0];
    organise_a(stack_a, count_a);
    *best_a -= 1;
    ft_printf("ra\n");
}

void    rotate_b(int *stack_b, int *count_b, int *best_b)
{
    int buff;

    buff = *count_b;
    stack_b[buff] = stack_b[0];
    organise_b(stack_b, count_b);
    // ft_printf("rotate B \n");
    *best_b -= 1;
    ft_printf("rb\n");
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
    ft_printf("rr\n");
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
    ft_printf("rra\n");
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
    ft_printf("rrb\n");
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
    ft_printf("rrr\n");
}

