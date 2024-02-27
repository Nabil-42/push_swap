/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:09:21 by nabboud           #+#    #+#             */
/*   Updated: 2024/02/27 12:59:57 by nabboud          ###   ########.fr       */
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
	int	buff;

	buff = args->count_a - 1;
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
int	verif_one_para(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '-' && (argv[1][i - i] != ' ' || i == 0))
			if (argv[1][i] == '-' && !(argv[1][i + 1] <= '9' && argv[1][i + 1] >= '0'))
				if(argv[1][i] == ' ' && !(argv[1][i + 1] <= '9' && argv[1][i + 1] >= '0'))
					if ((argv[1][i + 1] == '\0' && argv[1][i] == ' ') || (argv[1][0] == ' '))
							return (1);
		
		++i;
	}
	return (0);
}

int	verif3(t_args *args)
{
	int i;

	i = 0;
	while (i <= args->count_a)
	{
		if (args->stack_a[i] > args->stack_a[i + 1])
			return (0);
		++i;
	}
	return (1);
}
