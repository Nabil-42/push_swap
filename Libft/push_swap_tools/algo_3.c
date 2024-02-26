/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:36:14 by nabil             #+#    #+#             */
/*   Updated: 2024/02/26 12:22:46 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	nearest_small(int stack_a, int *stack_b, int count, t_args *args)
{
	if (verif_small(stack_a, stack_b, &count))
		return (scan_small(stack_b, &count));
	if (verif_big(stack_a, stack_b, &count))
		return (scan_small(stack_b, &count));
	args->duff = 0;
	args->j = 0;
	args->k = 0;
	while (args->k < count)
	{
		if (args->duff == 0 && stack_a - stack_b[args->k] < 0)
		{
			args->duff = stack_a - stack_b[args->k];
			args->j = args->k;
		}
		args->duff_2 = (stack_a - stack_b[args->k + 1]);
		if (args->duff < args->duff_2 && args->duff_2 < 0)
		{
			args->duff = args->duff_2;
			args->j = args->k + 1;
		}
		++(args->k);
	}
	if (args->duff == 0)
		return (-1);
	return (args->j);
}

void	calcule_2(t_args *args)
{
	args->i = 0;
	args->median_a = args->count_a / 2;
	args->median_b = args->count_b / 2;
	while (args->i < args->count_b)
	{
		args->buff = nearest_small(args->stack_b[args->i], args->stack_a,
				args->count_a, args);
		if (args->buff != -1)
			all_verif_2(args);
		if (args->i == 0)
			args->calcule_buff = args->calcule;
		if ((args->calcule <= args->calcule_buff || args->calcule == 0)
			&& args->buff != -1)
		{
			args->calcule_buff = args->calcule;
			args->best_b = args->i;
			args->best_a = args->buff;
			if (args->calcule == 0)
				break ;
		}
		++(args->i);
	}
}

void	calcule_1(t_args *args)
{
	args->i = 0;
	args->median_a = args->count_a / 2;
	args->median_b = args->count_b / 2;
	while (args->i < args->count_a)
	{
		args->buff = nearest_small(args->stack_a[args->i], args->stack_b,
				args->count_b, args);
		if (args->buff != -1)
			all_verif_1(args);
		if (args->i == 0)
			args->calcule_buff = args->calcule;
		if ((args->calcule <= args->calcule_buff || args->calcule == 0)
			&& args->buff != -1)
		{
			args->calcule_buff = args->calcule;
			args->best_a = args->i;
			args->best_b = args->buff;
			if (args->calcule == 0)
				break ;
		}
		++(args->i);
	}
}

int	push(t_args *args)
{
	while (!((args->best_a <= 0 && args->best_b <= 0)
			|| (args->best_a >= args->count_a && args->best_b >= args->count_b)
			|| (args->best_a <= 0 && args->best_b >= args->count_b)
			|| (args->best_a >= args->count_a && args->best_b <= 0)))
	{
		if ((args->best_a < args->median_a && (args->best_b < args->median_b
					|| args->median_b == 1)) && (args->best_a > 0
				&& args->best_b > 0))
			rotate_double(args);
		else if (args->best_a < args->median_a && args->best_a > 0)
			rotate_a(args->stack_a, &args->count_a, &args->best_a);
		else if (args->best_b < args->median_b && args->best_b > 0)
			rotate_b(args->stack_b, &args->count_b, &args->best_b);
		if ((args->best_a >= args->median_a && args->best_b >= args->median_b)
			&& (args->best_a != args->count_a && args->best_b != args->count_b)
			&& (args->count_a > 0 && args->count_b > 0))
			revers_rotate_double(args);
		else if (args->best_a >= args->median_a
			&& args->best_a != args->count_a)
			revers_rotate_a(args->stack_a, &args->count_a, &args->best_a);
		else if (args->best_b >= args->median_b
			&& args->best_b != args->count_b)
			revers_rotate_b(args->stack_b, &args->count_b, &args->best_b);
	}
	return (0);
}

void	three_left(int *stack_a, int count_a, t_args *args)
{
	if (verif_small(stack_a[2], stack_a, &count_a) && verif_big(stack_a[0],
			stack_a, &count_a))
	{
		swap_a(stack_a, args);
	}
	else if (verif_small(stack_a[0], stack_a, &count_a) && verif_big(stack_a[1],
			stack_a, &count_a))
	{
		swap_a(stack_a, args);
	}
	else if (verif_small(stack_a[1], stack_a, &count_a) && verif_big(stack_a[2],
			stack_a, &count_a))
	{
		swap_a(stack_a, args);
	}
}
