/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:09:21 by nabboud           #+#    #+#             */
/*   Updated: 2024/02/06 20:11:21 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	revers_rotate_b(int *stack_b, int *count_b, int *best_b)
{
	int	buff;
	int	storage;

	buff = *count_b;
	storage = stack_b[buff - 1];
	while (buff > 0)
	{
		stack_b[buff] = stack_b[buff - 1];
		--buff;
	}
	stack_b[buff] = storage;
	*best_b += 1;
	ft_printf("rrb\n");
}

void	revers_rotate_double(int *stack_a, int *count_a, int *stack_b,
		int *count_b, int *best_a, int *best_b)
{
	int	buff;
	int	storage;

	buff = *count_a;
	storage = stack_a[buff - 1];
	while (buff > 0)
	{
		stack_a[buff] = stack_a[buff - 1];
		--buff;
	}
	stack_a[buff] = storage;
	*best_a += 1;
	buff = *count_b;
	storage = stack_b[buff - 1];
	while (buff > 0)
	{
		stack_b[buff] = stack_b[buff - 1];
		--buff;
	}
	stack_b[buff] = storage;
	*best_b += 1;
	ft_printf("rrr\n");
}

void	push_a(int *stack_a, int *stack_b, int *count_a, int *count_b)
{
	int buff;

	buff = *count_a;
	while (buff >= 0)
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