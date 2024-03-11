/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:57:53 by nabil             #+#    #+#             */
/*   Updated: 2024/03/11 14:03:29 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../libft.h"

void	swap_a_bis(int *stack)
{
	int	i;
	int	buff;

	i = 0;
	buff = stack[i];
	stack[i] = stack[i + 1];
	stack[i + 1] = buff;
}

void	swap_b_bis(int *stack)
{
	int	i;
	int	buff;

	i = 0;
	buff = stack[i];
	stack[i] = stack[i + 1];
	stack[i + 1] = buff;
}

void	swap_ss_bis(int *stack_a, int *stack_b)
{
	int	i;
	int	*buff;

	buff = (int *)malloc(sizeof(int));
	i = 0;
	buff[i] = stack_a[i];
	stack_a[i] = stack_a[i + 1];
	stack_a[i + 1] = buff[i];
	buff[i] = stack_b[i];
	stack_b[i] = stack_b[i + 1];
	stack_b[i + 1] = buff[i];
	free(buff);
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
