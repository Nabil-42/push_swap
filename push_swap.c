/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:08:04 by nabil             #+#    #+#             */
/*   Updated: 2024/03/11 09:27:34 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
		push_b(args);
	if (args->count_a > 2)
		three_left(args->stack_a, args->count_a, args);
	while (args->count_b != 0)
		(calcule_2(args), push(args), push_a(args));
	args->best_a = scan_small(args->stack_a, &(args->count_a));
	push(args);
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
	free(args->stack_a);
	free(args->stack_b);
	return (0);
}

int	push_swap_bis(t_args *args, char **argv, int argc)
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = ft_split(argv[1], ' ');
	argc = count_tab(ptr);
	if (verif1(ptr) == 0 || verif2(argc, ptr) == 0)
		return (ft_freetab(ptr), ft_printf("Error\n"), 0);
	args->count_a = argc;
	args->count_b = 0;
	args->stack_a = (int *)malloc(sizeof(int) * (argc + 1));
	args->stack_b = (int *)malloc(sizeof(int) * (argc + 1));
	if (!args->stack_a || !args->stack_b)
		return (ft_freetab(ptr), 0);
	while (ptr[i])
	{
		args->stack_a[i] = ft_atoi(ptr[i]);
		args->stack_b[i] = 0;
		++i;
	}
	if (verif3(args))
		return (free(args->stack_a), free(args->stack_b), ft_freetab(ptr), 0);
	(algo(args), free(args->stack_a), free(args->stack_b), ft_freetab(ptr));
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
	if (argc == 2)
		if (verif_one_para(argv))
			if (verif1(argv) == 0 || verif2(argc, argv) == 0)
				return (push_swap_bis(&args, argv, argc), 0);
	if (verif1(argv) == 0 || verif2(argc, argv) == 0)
	{
		ft_printf("Error \n");
		return (0);
	}
	else
	{
		push_swap(&args, argv, argc);
	}
}
