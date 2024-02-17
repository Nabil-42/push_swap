/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:08:04 by nabil             #+#    #+#             */
/*   Updated: 2024/02/17 18:55:32 by nabboud          ###   ########.fr       */
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

void	algo(t_args *args, int argc)
{
	int	best_a;
	int	best_b;

	best_a = 0;
	best_b = 0;
	args->stack_a.count = argc - 1;
	args->stack_b.count = 0;
	if (count_a > 3)
		push_b(args);
	if (count_a > 3)
		push_b(stack_a, stack_b, &count_a, &count_b);
	while (count_a > 3)
		(calcule(stack_a, stack_b, count_a, count_b, &best_a, &best_b),
			push(&best_a, &best_b, stack_a, stack_b, count_a, count_b),
			push_b(stack_a, stack_b, &count_a, &count_b));
	if (count_a > 2)
		three_left(stack_a, count_a);
	while (count_b != 0)
		(calcule(stack_b, stack_a, count_b, count_a, &best_b, &best_a),
			push(&best_a, &best_b, stack_a, stack_b, count_a, count_b),
			push_a(stack_a, stack_b, &count_a, &count_b));
	best_a = scan_small(stack_a, &count_a);
	push(&best_a, &best_b, stack_a, stack_b, count_a, count_b);
}

int	push_swap(t_args *args, char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	args->stack_a.tab = (int *)malloc(sizeof(int) * (argc - 1));
	args->stack_b.tab = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack_a || !stack_b)
		return (0);
	while (argv[j])
	{
		args->stack_a.tab[i] = ft_atoi(argv[j]);
		++i;
		++j;
	}
	algo(args, argc);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;
	
	args = malloc(sizeof(t_args));
	if (!args)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!(argc >= 2))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (verif1(argv) == 0 || verif2(argc, argv) == 0)
	{
		ft_printf("Error\n");
		return (ft_printf("Error\n"), 0);
	}
	push_swap(&args, argv, argc);
}
