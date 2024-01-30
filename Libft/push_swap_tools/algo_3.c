/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:36:14 by nabil             #+#    #+#             */
/*   Updated: 2024/01/21 09:52:37 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int     verif_1(int i, int buff, int median_a, int median_b, int calcule)
{
    if (i <= median_a && buff <= median_b)
        {
            if (i >= buff )
                calcule = i;
            else{
                calcule = buff;
            }
            return(calcule);
        }
        return(calcule);
}

int     verif_2(int i, int buff, int median_a, int median_b, int count_a, int count_b, int calcule)
{
    if (i >= median_a && buff >= median_b )
        {
            if (i <= buff)
            {
                calcule = count_a - i;
            }
            else{
                calcule = count_b - buff;
            }

            return(calcule);
        }
        return(calcule);
}

int     verif_3(int i, int buff, int median_a, int median_b, int count_a, int count_b, int calcule)
{
    if ((i >= median_a && buff < median_b) || (i < median_a && buff >= median_b))
        {
            if (i <= median_a && median_b == 1)
            {
                calcule = i;  
            }
            else if (i >= median_a && median_b == 1)
            {
                calcule = (count_a - i);     
            }
            else if ( i < median_a)
            {
                calcule = i + (count_b - buff);   
            }
            else{   
                calcule = buff + (count_a - i);
            }
            return(calcule);
        }
        return(calcule);
}

int    nearest_small(int stack_a, int *stack_b, int count)
{
    int     i;
    int     j;
    int     buff;
    int     buff_2;
    
    if (verif_small(stack_a, stack_b, &count))
        return (scan_small(stack_b, &count));  
    if (verif_big(stack_a, stack_b, &count))
        return (scan_small(stack_b, &count));
    buff = 0;
    j = 0;
    i = 0;
    while(i < count)
    {
        if (buff == 0 && stack_a - stack_b[i] < 0)
        {
            buff = stack_a - stack_b[i];
            j = i;
        }
        buff_2 = (stack_a - stack_b[i + 1]);
        if (buff < buff_2 && buff_2 < 0)
        {
            buff = buff_2;
            j = i + 1;    
        }
        ++i;
    }
        if (buff == 0)
            return (-1);
    return(j);
}


void    calcule(int *stack_a, int *stack_b, int count_a, int count_b, int *best_a, int *best_b)
{
    int     median_a;
    int     median_b;
    int     buff;
    int     i;
    int     calcule;
    int     calcule_buff;
    
    calcule_buff = 0;  
    i = 0;
    median_a = count_a / 2;
    median_b = count_b / 2;
    while(i < count_a)
    {
    buff = nearest_small(stack_a[i], stack_b, count_b);
    if (buff != -1)
    {
    calcule = 0;
    calcule = verif_1(i, buff, median_a, median_b, calcule);
    calcule = verif_2(i, buff, median_a, median_b, count_a, count_b, calcule);
    calcule = verif_3(i, buff, median_a, median_b, count_a, count_b, calcule);
    }
    if (i == 0)
        calcule_buff = calcule;
    if ((calcule <= calcule_buff || calcule == 0) && buff != -1)
    {
        calcule_buff = calcule;
        *best_a = i;
        *best_b = buff; 
        if (calcule == 0)
            break;
    }
    ++i;
    }
}

int     push(int *best_a, int *best_b, int *stack_a, int *stack_b, int count_a, int count_b)
{
    int     median_a;
    int     median_b;
    
    median_a = count_a / 2;
    median_b = count_b / 2;
    while (!((*best_a <= 0 && *best_b <= 0) 
        || (*best_a >= count_a && *best_b >= count_b) 
        || (*best_a <= 0 && *best_b >= count_b)
        || (*best_a >= count_a && *best_b <= 0)))
    {     
        if ((*best_a < median_a && *best_b < median_b) 
                && (*best_a > 0 && *best_b > 0))
                rotate_double(stack_a, &count_a, stack_b, &count_b, best_a, best_b);
        else if (*best_a < median_a && *best_a > 0)
                rotate_a(stack_a, &count_a, best_a);
        else if (*best_b < median_b && *best_b > 0)
                rotate_b(stack_b, &count_b, best_b);
        if ((*best_a >= median_a && *best_b >= median_b) 
                && (*best_a != count_a && *best_b != count_b)
                && (count_a > 0 && count_b > 0))
                revers_rotate_double(stack_a, &count_a, stack_b, &count_b, best_a, best_b);
        else if (*best_a >= median_a && *best_a != count_a)
                revers_rotate_a(stack_a, &count_a, best_a);
        else if (*best_b >= median_b && *best_b != count_b)
                revers_rotate_b(stack_b, &count_b, best_b);  
    }
    return (0);
}

void     three_left(int *stack_a, int count_a)
{
    if (verif_small(stack_a[3], stack_a, &count_a) && verif_big(stack_a[0], stack_a, &count_a))
        {
            swap_a(stack_a);
        }
    else if (verif_small(stack_a[1], stack_a, &count_a) && verif_big(stack_a[2], stack_a, &count_a))
    {
        swap_a(stack_a);
    }
    else if (verif_small(stack_a[2], stack_a, &count_a) && verif_big(stack_a[3], stack_a, &count_a))
    {
        swap_a(stack_a);
    }
    
}