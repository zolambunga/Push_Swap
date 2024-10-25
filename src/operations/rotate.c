/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:20:07 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/25 01:18:37 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

t_stack	*ft_ra(t_stack **top, bool print)
{
	rotate(top);
	if (print)
		write(1, "ra\n", 3);
	return (*top);
}

t_stack	*ft_rb(t_stack **top, bool print)
{
	rotate(top);
	if (print)
		write(1, "rb\n", 3);
	return (*top);
}

void	ft_rr(t_stack **topa, t_stack **topb)
{
	(*topa) = ft_ra(topa, false);
	(*topb) = ft_rb(topb, false);
	write(1, "rr\n", 3);
}
