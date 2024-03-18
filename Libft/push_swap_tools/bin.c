/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:09:21 by nabboud           #+#    #+#             */
/*   Updated: 2024/03/18 15:44:59 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../push_swap.h"
#include <limits.h>

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		++i;
	}
	return (i);
}

int	verif1(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '-' && !(argv[i][1] <= '9' && argv[i][1] >= '0'))
			return (0);
		if (argv[i][0] != '-' && !(argv[i][0] <= '9' && argv[i][0] >= '0'))
			return (0);
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN
			|| ft_atoi(argv[i]) == -1)
			return (0);
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] <= '9') && (argv[i][j] >= '0')))
				return (0);
			++j;
		}
		j = 1;
		++i;
	}
	return (1);
}

int	verif3(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->count_a - 1)
	{
		if (args->stack_a[i] > args->stack_a[i + 1])
			return (0);
		++i;
	}
	return (1);
}

int	verif1_bis(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '-' && !(argv[i][1] <= '9' && argv[i][1] > '0'))
			return (0);
		if (argv[i][0] != '-' && !(argv[i][0] <= '9' && argv[i][0] >= '0'))
			return (0);
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN
			|| ft_atoi(argv[i]) == -1)
			return (0);
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] <= '9') && (argv[i][j] >= '0')))
				return (0);
			++j;
		}
		j = 1;
		++i;
	}
	return (1);
}
