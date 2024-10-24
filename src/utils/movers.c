/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:50:36 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 23:04:10 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_putcheap_n_target_ontop(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (!ft_isontop(cheap, (*a)))
	{
		if (cheap->midpoint_up)
			ft_ra(a, true);
		else
			ft_rra(a, true);
		ft_update_index(*a, false);
	}
	while (!ft_isontop(cheap->target, (*b)))
	{
		if (cheap->target->midpoint_up)
			ft_rb(b, true);
		else
			ft_rrb(b, true);
		ft_update_index(*b, false);
	}
}

void	ft_atob(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = ft_findmin_cost(*a);
	if (cheap->push_cost != cheap->target->push_cost)
		ft_putcheap_n_target_ontop(a, b, cheap);
	else
	{
		while (!ft_isontop(cheap, (*a)) && !ft_isontop(cheap->target, (*b)))
		{
			if (cheap->midpoint_up)
				ft_rr(a, b);
			else
				ft_rrr(a, b);
			ft_update_index(*a, false);
		}
	}
	ft_pb(a, b);
	ft_update_index(*a, true);
	ft_update_index(*b, true);
}

void	ft_btoa(t_stack **b, t_stack **a)
{
	while (!ft_isontop((*b)->target, (*a)))
	{
		if ((*b)->target->midpoint_up)
			ft_ra(a, true);
		else
			ft_rra(a, true);
		ft_update_index(*a, false);
	}
	ft_pa(a, b);
	ft_update_index(*a, true);
	ft_update_index(*b, true);
}
