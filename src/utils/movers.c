/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:50:36 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/19 17:18:29 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ft_atob(t_stack **a, t_stack **b)
{
    t_stack *cheap;

    cheap = ft_findmin_cost(*a);
    if (!ft_isontop(cheap, (*a)))
    {
            if (cheap->midpoint_up)
                ft_ra(a, true);
            else
                ft_rra(a, true);
    }
    if (!ft_isontop(cheap->target, (*b)))
    {
            if (cheap->target->midpoint_up)
                ft_rb(b, true);
            else
                ft_rrb(b, true);
    }
    if (ft_isontop(cheap->target, (*b))
        && ft_isontop(cheap, (*a)))
        ft_pb(a, b);
}

void    ft_btoa(t_stack **b, t_stack **a)
{
    t_stack *cheap;
    
    cheap = ft_findmin_cost(*b);

    if (!ft_isontop(cheap, (*b)))
    {
            if (cheap->midpoint_up)
                ft_rb(b, true);
            else
                ft_rrb(b, true);
    }
    if (!ft_isontop(cheap->target, (*a)))
    {
            if (cheap->target->midpoint_up)
                ft_ra(b, true);
            else
                ft_rra(b, true);
    }
        if (ft_isontop(cheap->target, (*b)))
            ft_pa(b, a);
}
