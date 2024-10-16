/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:48:01 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/16 16:56:35 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	rev_rotate(t_stack **top)
{
	t_stack	*bottom;

	bottom = ft_lst_findlast(*top);
	bottom->next = (*top);
	(*top)->prev = bottom;
	(*top) = bottom;
	bottom->prev->next = NULL;
}

t_stack	*rra(t_stack **top, bool print)
{
	rev_rotate(top);
	if (print)
		write(1, "rra\n", 4);
	return (*top);
}

t_stack	*rrb(t_stack **top, bool print)
{
	rev_rotate(top);
	if (print)
		write(1, "rrb\n", 4);
	return (*top);
}

void	rrr(t_stack **topa, t_stack **topb)
{
	(*topa) = rra(topa, false);
	(*topb) = rrb(topb, false);
	write(1, "rrr\n", 4);
}
