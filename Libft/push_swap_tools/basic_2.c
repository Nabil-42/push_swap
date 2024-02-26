/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:32:29 by nabil             #+#    #+#             */
/*   Updated: 2024/02/26 14:41:41 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	push_b(t_args *args)
{
	int	buff;

	buff = args->count_b;
	while (buff >= 0)
	{
		args->stack_b[buff + 1] = args->stack_b[buff];
		--buff;
	}
	args->stack_b[0] = args->stack_a[0];
	args->count_b += 1;
	args->count_a -= 1;
	organise_a(args->stack_a, &args->count_a);
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

void	rotate_double(t_args *args)
{
	int	buff;

	buff = args->count_a;
	args->stack_a[buff] = args->stack_a[0];
	organise_a(args->stack_a, &args->count_a);
	args->best_a -= 1;
	buff = args->count_b;
	args->stack_b[buff] = args->stack_b[0];
	organise_b(args->stack_b, &args->count_b);
	args->best_b -= 1;
	ft_printf("rr\n");
}

void	revers_rotate_a(int *stack_a, int *count_a, int *best_a)
{
	int	buff;
	int	storage;

	buff = *count_a - 1;
	storage = stack_a[buff];
	while (buff > 0)
	{
		stack_a[buff] = stack_a[buff - 1];
		--buff;
	}
	stack_a[0] = storage;
	*best_a += 1;
	ft_printf("rra\n");
}

