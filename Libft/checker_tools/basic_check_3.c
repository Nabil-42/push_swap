/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:15:14 by nabil             #+#    #+#             */
/*   Updated: 2024/03/11 14:17:39 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../libft.h"

void	revers_rotate_b_bis(int *stack_b, int *count_b, int *best_b)
{
	int	storage;
	int	i;

	if (*count_b <= 1)
		return ;
	storage = stack_b[*count_b - 1];
	i = *count_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = storage;
	*best_b += 1;
}

void	revers_rotate_double_bis(t_args *args)
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
}

void	push_a_bis(t_args *args)
{
	int	buff;

	buff = args->count_a;
	while (buff >= 0)
	{
		args->stack_a[buff + 1] = args->stack_a[buff];
		--buff;
	}
	args->stack_a[0] = args->stack_b[0];
	args->count_a += 1;
	args->count_b -= 1;
	organise_b(args->stack_b, &args->count_b);
}

void	parth_error(t_args *args)
{
	free(args->stack_a);
	free(args->stack_b);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
