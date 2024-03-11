/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:08:08 by nabil             #+#    #+#             */
/*   Updated: 2024/03/09 14:43:26 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void path(char *str)
{
    if (str[0] == 'p' && str[1] == 'a')
        push_a(t_args);
    if (str[0] == 'p' && str[1] == 'b')
        push_b;
    if (str[0] == 'r' && str[1] == 'a')
        rotate_a
    if (str[0] == 'r' && str[1] == 'b')
        rotate_b
    if (str[0] == 'r' && str[1] == 'r')
        rotate_double
    if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
        revers_rotate_a
    if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
        revers_rotate_b
    if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
        revers_rotate_double;
}

void traduction(char *instruction)
{
    unsigned char c0;
    char c1;
    int nbr;
    
    
}
int main(int argc, char **argv)
{
    char *instruction;
    
    if (argc != 2)
        return (0);
    if (instruction == NULL)
        return (0);
    while (1)
    {
        path(get_next_line(0));
        if (get_next_line(0) == NULL || instruction[2] != '\n')
            break;
        
      
    }    
}
