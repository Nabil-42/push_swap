/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:15:04 by nabil             #+#    #+#             */
/*   Updated: 2024/03/11 15:01:27 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../libft.h"

void	push_b_bis(t_args *args)
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
}

void	rotate_a_bis(int *stack_a, int *count_a, int *best_a)
{
	int	buff;

	buff = *count_a;
	stack_a[buff] = stack_a[0];
	organise_a(stack_a, count_a);
	*best_a -= 1;
}

void	rotate_b_bis(int *stack_b, int *count_b, int *best_b)
{
	int	buff;

	buff = *count_b;
	stack_b[buff] = stack_b[0];
	organise_b(stack_b, count_b);
	*best_b -= 1;
}

void	rotate_double_bis(t_args *args)
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
}

void	revers_rotate_a_bis(int *stack_a, int *count_a, int *best_a)
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
}
