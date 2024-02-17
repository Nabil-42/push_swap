/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:32:29 by nabil             #+#    #+#             */
/*   Updated: 2024/02/12 16:17:51 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	push_b(int *stack_a, int *stack_b, int *count_a, int *count_b)
{
	int	buff;

	buff = *count_b;
	while (buff >= 0)
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

void	rotate_a(int *stack_a, int *count_a, int *best_a)
{
	int	buff;

	buff = *count_a;
	stack_a[buff] = stack_a[0];
	organise_a(stack_a, count_a);
	*best_a -= 1;
	ft_printf("ra\n");
}

void	rotate_b(int *stack_b, int *count_b, int *best_b)
{
	int	buff;

	buff = *count_b;
	stack_b[buff] = stack_b[0];
	organise_b(stack_b, count_b);
	*best_b -= 1;
	ft_printf("rb\n");
}

void	rotate_double(int *stack_a, int *count_a, int *stack_b, int *count_b,
		int *best_a, int *best_b)
{
	int	buff;

	buff = *count_a;
	stack_a[buff] = stack_a[0];
	organise_a(stack_a, count_a);
	*best_a -= 1;
	buff = *count_b;
	stack_b[buff] = stack_b[0];
	organise_b(stack_b, count_b);
	*best_b -= 1;
	ft_printf("rr\n");
}

void	revers_rotate_a(int *stack_a, int *count_a, int *best_a)
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
	ft_printf("rra\n");
}
