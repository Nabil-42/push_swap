/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:49:16 by nabboud           #+#    #+#             */
/*   Updated: 2024/02/26 10:27:46 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	verif_1(t_args *args)
{
	if (args->i <= args->median_a && args->buff <= args->median_b)
	{
		if (args->i >= args->buff)
			args->calcule = args->i;
		else
		{
			args->calcule = args->buff;
		}
		return (args->calcule);
	}
	return (args->calcule);
}

int	verif_2(t_args *args)
{
	if (args->i >= args->median_a && args->buff >= args->median_b)
	{
		if ((args->count_a - args->i) <= args->count_b - args->buff)
		{
			args->calcule = args->count_b - args->buff;
			if (args->count_b % 2 != 0 && args->buff == args->median_b)
				args->calcule += 1;
		}
		else
		{
			args->calcule = args->count_a - args->i;
			if (args->count_a % 2 != 0 && args->i == args->median_a)
				args->calcule += 1;
		}
		return (args->calcule);
	}
	return (args->calcule);
}

int	verif_3(t_args *args)
{
	if ((args->i >= args->median_a && args->buff < args->median_b)
		|| (args->i < args->median_a && args->buff >= args->median_b))
	{
		if (args->i <= args->median_a && args->median_b == 1)
				args->calcule = args->i;
		else if (args->i >= args->median_a && args->median_b == 1)
		{
			args->calcule = (args->count_a - args->i);
			if (args->count_a % 2 != 0 && args->i == args->median_a)
				args->calcule += 1;
		}
		else if (args->i < args->median_a)
		{
			args->calcule = args->i + (args->count_b - args->buff);
		}
		else
		{
			args->calcule = args->buff + (args->count_a - args->i);
			if (args->count_a % 2 != 0 && args->i == args->median_a)
				args->calcule += 1;
		}
		return (args->calcule);
	}
	return (args->calcule);
}

void	all_verif_2(t_args *args)
{
			args->calcule = 0;
			args->calcule = verif_6(args);
			args->calcule = verif_5(args);
			args->calcule = verif_4(args);
}

void	all_verif_1(t_args *args)
{
			args->calcule = 0;
			args->calcule = verif_3(args);
			args->calcule = verif_2(args);
			args->calcule = verif_1(args);
}
