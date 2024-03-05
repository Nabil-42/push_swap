/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:09:21 by nabboud           #+#    #+#             */
/*   Updated: 2024/03/05 17:19:03 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../push_swap.h"

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
	while (argv[i])
	{
		if (argv[i][0] == '-' && !(argv[i][1] <= '9' && argv[i][1] >= '0'))
			return (0);
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
