/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:08:08 by nabil             #+#    #+#             */
/*   Updated: 2024/03/11 15:03:24 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../push_swap.h"

void	path(char *str, t_args *args)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		swap_a_bis(args->stack_a);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		swap_b_bis(args->stack_b);
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		push_a_bis(args);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		push_b_bis(args);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		revers_rotate_a_bis(args->stack_a, &args->count_a, &args->best_a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		revers_rotate_b_bis(args->stack_b, &args->count_b, &args->best_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		revers_rotate_double_bis(args);
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		rotate_a_bis(args->stack_a, &args->count_a, &args->best_a);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		rotate_b_bis(args->stack_b, &args->count_b, &args->best_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		rotate_double_bis(args);
	else
		parth_error(args);
}

int	lecture(t_args *args)
{
	char	*instruction;
	int		i;

	i = 0;
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
		{
			free(instruction);
			break ;
		}
		path(instruction, args);
		free(instruction);
	}
	while (i + 1 < args->count_a)
	{
		if (args->stack_a[i] > args->stack_a[i + 1])
			return (ft_printf("KO\n"));
		++i;
	}
	return (ft_printf("OK\n"));
}

int	trad_bis(t_args *args, char **argv, int argc)
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
	lecture(args);
	(free(args->stack_a), free(args->stack_b), ft_freetab(ptr));
	return (0);
}

int	trad(t_args *args, char **argv, int argc)
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
	lecture(args);
	free(args->stack_a);
	free(args->stack_b);
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
				return (trad_bis(&args, argv, argc), 0);
	if (verif1(argv) == 0 || verif2(argc, argv) == 0)
	{
		ft_printf("Error \n");
		return (0);
	}
	else
	{
		trad(&args, argv, argc);
	}
}
