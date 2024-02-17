/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:39:32 by nabil             #+#    #+#             */
/*   Updated: 2024/02/06 20:07:37 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	organise_a(int *stack, int *count_a)
{
	int	i;

	i = 0;
	while (i < *count_a)
	{
		stack[i] = stack[i + 1];
		++i;
	}
}

void	organise_b(int *stack, int *count_b)
{
	int	i;

	i = 0;
	while (i < *count_b)
	{
		stack[i] = stack[i + 1];
		++i;
	}
}

void	swap_a(int *stack)
{
	int	i;
	int	*buff;

	buff = (int *)malloc(sizeof(int));
	i = 0;
	buff[i] = stack[i];
	stack[i] = stack[i + 1];
	stack[i + 1] = buff[i];
	free(buff);
	ft_printf("sa\n");
}

void	swap_b(int *stack)
{
	int	i;
	int	*buff;

	buff = (int *)malloc(sizeof(int));
	i = 0;
	buff[i] = stack[i];
	stack[i] = stack[i + 1];
	stack[i + 1] = buff[i];
	free(buff);
	ft_printf("sb\n");
}

void	swap_ss(int *stack_a, int *stack_b)
{
	int	i;
	int	*buff;

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
