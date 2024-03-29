/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:46:15 by nabil             #+#    #+#             */
/*   Updated: 2024/03/05 16:19:52 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	verif_4(t_args *args)
{
	if (args->i <= args->median_b && args->buff <= args->median_a)
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

int	verif_5(t_args *args)
{
	if (args->i >= args->median_b && args->buff >= args->median_a)
	{
		if ((args->count_b - args->i) <= args->count_a - args->buff)
		{
			args->calcule = args->count_a - args->buff;
			if (args->count_a % 2 != 0 && args->buff == args->median_a)
				args->calcule += 1;
		}
		else
		{
			args->calcule = args->count_b - args->i;
			if (args->count_b % 2 != 0 && args->i == args->median_b)
				args->calcule += 1;
		}
		return (args->calcule);
	}
	return (args->calcule);
}

int	verif_6(t_args *args)
{
	if ((args->i >= args->median_b && args->buff < args->median_a)
		|| (args->i < args->median_b && args->buff >= args->median_a))
	{
		if (args->i <= args->median_b && args->median_a == 1)
			args->calcule = args->i;
		else if (args->i >= args->median_b && args->median_a == 1)
		{
			args->calcule = (args->count_b - args->i);
			if (args->count_b % 2 != 0 && args->i == args->median_b)
				args->calcule += 1;
		}
		else if (args->i < args->median_b)
		{
			args->calcule = args->i + (args->count_a - args->buff);
		}
		else
		{
			args->calcule = args->buff + (args->count_b - args->i);
			if (args->count_b % 2 != 0 && args->i == args->median_b)
				args->calcule += 1;
		}
		return (args->calcule);
	}
	return (args->calcule);
}

void	ft_freetab_int(int *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(&tab[i]);
	}
	free(tab);
}
