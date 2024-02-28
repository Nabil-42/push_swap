/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:08:04 by nabil             #+#    #+#             */
/*   Updated: 2024/02/28 18:04:59 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	verif1(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-' && !(argv[i][0] <= '9' && argv[i][0] >= '0'))
			return (0);
		if (ft_atoi(argv[i]) > 2147483747 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		while (argv[i][j])
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

int	verif2(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (j < argc && argc >= 3)
	{
		i = j + 1;
		while (argv[i])
		{
			if (ft_strcmp(argv[j], argv[i]) == 0)
				return (0);
			++i;
		}
		++j;
	}
	return (1);
}

void	algo(t_args *args)
{
	args->best_a = 0;
	args->best_b = 0;
	if (args->count_a > 3)
		push_b(args);
	if (args->count_a > 3)
		push_b(args);
	while (args->count_a > 3)
		(calcule_1(args), push(args), push_b(args));
	if (args->count_a > 2)
		three_left(args->stack_a, args->count_a, args);
	while (args->count_b != 0)
		(calcule_2(args), push(args), push_a(args));
	args->best_a = scan_small(args->stack_a, &(args->count_a));
	push(args);
	free(args->stack_a);
	free(args->stack_b);
}

int	push_swap(t_args *args, char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	args->count_a = argc - 1;
	args->count_b = 0;
	args->stack_a = (int *)malloc(sizeof(int) * (argc));
	args->stack_b = (int *)malloc(sizeof(int) * (argc));
	if (!args->stack_a || !args->stack_b)
		return (0);
	while (argv[j])
	{
		args->stack_a[i] = ft_atoi(argv[j]);
		args->stack_b[i] = 0;
		++i;
		++j;
	}
	if (verif3(args))
		return (free(args->stack_a), free(args->stack_b), 0);
	algo(args);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc == 1)
		return (0);
	if (!(argc >= 2))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (verif1(argv) == 0 || verif2(argc, argv) == 0)
		return (ft_printf("Error\n"), 0);
	push_swap(&args, argv, argc);
}
