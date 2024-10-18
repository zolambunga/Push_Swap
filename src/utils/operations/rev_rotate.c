/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:48:01 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/18 11:28:25 by zombunga         ###   ########.fr       */
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

t_stack	*ft_rra(t_stack **top, bool print)
{
	rev_rotate(top);
	if (print)
		write(1, "rra\n", 4);
	return (*top);
}

t_stack	*ft_rrb(t_stack **top, bool print)
{
	rev_rotate(top);
	if (print)
		write(1, "rrb\n", 4);
	return (*top);
}

void	ft_rrr(t_stack **topa, t_stack **topb)
{
	(*topa) = ft_rra(topa, false);
	(*topb) = ft_rrb(topb, false);
	write(1, "rrr\n", 4);
}
