/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:59:57 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/18 13:09:54 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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