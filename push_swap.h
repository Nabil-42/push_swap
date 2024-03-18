/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:33:28 by nabil             #+#    #+#             */
/*   Updated: 2024/03/18 14:01:23 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

int		verif1_bis(char **argv);
int		verif3_bis(t_args *arg);
int		verif1(char **argv);
int		verif2(int argc, char **argv);
void	swap_b_bis(int *stack);
void	swap_a_bis(int *stack);
void	swap_ss_bis(int *stack_a, int *stack_b);

void	push_b_bis(t_args *args);
void	rotate_a_bis(int *stack_a, int *count_a, int *best_a);
void	rotate_b_bis(int *stack_b, int *count_b, int *best_b);
void	rotate_double_bis(t_args *args);
void	revers_rotate_a_bis(int *stack_a, int *count_a, int *best_a);
void	revers_rotate_b_bis(int *stack_b, int *count_b, int *best_b);
void	revers_rotate_double_bis(t_args *args);
void	push_a_bis(t_args *args);
void	parth_error(t_args *args);

#endif
