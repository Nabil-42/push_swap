/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:09:21 by nabboud           #+#    #+#             */
/*   Updated: 2024/02/25 12:50:34 by nabil            ###   ########.fr       */
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

void	revers_rotate_double(t_args *args)
{
	int	buff;
	int	storage;

	buff = args->count_a;
	storage = args->stack_a[buff - 1];
	while (buff > 0)
	{
		args->stack_a[buff] = args->stack_a[buff - 1];
		--buff;
	}
	args->stack_a[buff] = storage;
	args->best_a += 1;
	buff = args->count_b;
	storage = args->stack_b[buff - 1];
	while (buff > 0)
	{
		args->stack_b[buff] = args->stack_b[buff - 1];
		--buff;
	}
	args->stack_b[buff] = storage;
	args->best_b += 1;
	ft_printf("rrr\n");
}

void	push_a(t_args *args)
{
	int buff;

	buff = args->count_a;
	while (buff >= 0)
	{
		args->stack_a[buff + 1] = args->stack_a[buff];
		--buff;
	}
	args->stack_a[0] = args->stack_b[0];
	args->count_a += 1;
	args->count_b -= 1;
	organise_b(args->stack_b, &(args->count_b));
	ft_printf("pa\n");
}
