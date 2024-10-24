/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:31:09 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 23:00:54 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_final_sort(t_stack **a)
{
	while (!ft_issorted(NULL, *a))
	{
		if ((ft_findmin(*a))->midpoint_up)
			ft_ra(a, true);
		else
			ft_rra(a, true);
	}
}

void	ft_send_from_b_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		ft_update_index(*a, true);
		ft_update_index(*b, true);
		ft_settarget_b(*b, *a);
		ft_btoa(b, a);
	}
}

void	ft_send_to_b_until_a_is_three(t_stack **a, t_stack **b)
{
	while (ft_lst_size(*a) != 3 && !ft_issorted(NULL, *a))
	{
		ft_update_index(*b, true);
		ft_update_index(*a, true);
		ft_settarget_a(*a, *b);
		ft_pushcost(*a, *b, ft_lst_size(*a), ft_lst_size(*b));
		ft_atob(a, b);
	}
}

void	ft_send_two_numbers_to_a(t_stack **a, t_stack **b)
{
	if (ft_lst_size(*a) != 3 && !ft_issorted(NULL, *a))
		ft_pb(a, b);
	if (ft_lst_size(*a) != 3 && !ft_issorted(NULL, *a))
		ft_pb(a, b);
}
