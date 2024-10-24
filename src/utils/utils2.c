/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:59:57 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 15:40:32 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int ft_abs(int num)
{
    if (num < 0) {
        return (-num);
    }
    return (num);
}

int ft_isontop(t_stack *node, t_stack *top)
{
    return((node) == (top));
}

t_stack *ft_findmin(t_stack *list)
{
    t_stack     *min;
    t_stack     *tmp;

    tmp = list;
    min = list;
    while(tmp)
    {
        if (min->nbr > tmp->nbr)
            min = tmp;
        tmp = tmp->next;
    }
    return (min);
}

t_stack *ft_findmax(t_stack *list)
{
    t_stack *max;
    t_stack *tmp;

    tmp = list;
    max = list;
    while(tmp)
    {
        if (max->nbr < tmp->nbr)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}

t_stack *ft_findmin_cost(t_stack *stack)
{
    t_stack     *min;
    t_stack     *tmp;

    tmp = stack;
    min = stack;
    while(tmp)
    {
        if (min->total_push_cost > tmp->total_push_cost)
            min = tmp;
        tmp = tmp->next;
    }
    return (min);
}