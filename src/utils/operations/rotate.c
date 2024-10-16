/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:20:07 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/11 14:19:20 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	rotate(t_stack **top)
{
	t_stack		*bottom;

	bottom = ft_lst_findlast(*top);
	(*top)->prev = bottom;
	bottom->next = (*top);
	(*top) = (*top)->next;
	(*top)->prev = NULL;
	bottom->next->next = NULL;
}

t_stack	*ra(t_stack **top, bool print)
{
	rotate(top);
	if (print)
		write(1, "ra\n", 3);
	return (*top);
}

t_stack	*rb(t_stack **top, bool print)
{
	rotate(top);
	if (print)
		write(1, "rb\n", 3);
	return (*top);
}

void	rr(t_stack **topa, t_stack **topb)
{
	(*topa) = ra(topa, false);
	(*topb) = rb(topb, false);
	write(1, "rr\n", 3);
}
