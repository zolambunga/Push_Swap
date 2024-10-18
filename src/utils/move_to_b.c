/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:47 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/18 14:19:33 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack *ft_atob(t_stack **a, t_stack **b)
{
    t_stack *max;
    t_stack *min;
    t_stack *aa;
    t_stack *bb;

    aa = (*a);
    bb = (*b);
    max = ft_findmax(*b);
    min = ft_findmax(*b);
    while(bb)
    {
        while(aa)
        {
            if (aa->nbr > max->nbr)
            aa = aa->next;
        }
        bb = bb->next;
    }
}