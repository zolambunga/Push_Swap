/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:03:58 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/25 02:22:20 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_cost_calculus(t_stack *stack, int stack_size)
{
	int	cost;

	cost = (stack_size - stack->index);
	if (stack->midpoint_up)
		return (stack->index);
	else
		return (cost);
}

void	ft_pushcost(t_stack *a, int len_a, int len_b)
{
	int		to_bringa;
	int		to_bringb;

	while (a)
	{
		to_bringa = ft_cost_calculus(a, len_a);
		to_bringb = ft_cost_calculus(a->target, len_b);
		a->push_cost = to_bringa;
		a->target->push_cost = to_bringb;
		if (to_bringa == to_bringb)
			a->total_push_cost = a->push_cost;
		else
			a->total_push_cost = to_bringa + to_bringb;
		a = a->next;
	}
}
