/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:53:46 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/16 16:55:52 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	swap(t_stack **top)
{
	t_stack	*second;

	second = (*top)->next;
	(*top)->prev = second;
	(*top)->next = second->next;
	second->prev = NULL;
	second->next = (*top);
	(*top) = second;
}

t_stack	*sa(t_stack **top, bool print)
{
	swap(top);
	if (print)
		write(1, "sa\n", 3);
	return (*top);
}

t_stack	*sb(t_stack **top, bool print)
{
	swap(top);
	if (print)
		write(1, "sb\n", 3);
	return (*top);
}

void	ss(t_stack **topa, t_stack **topb)
{
	(*topa) = sa(topa, false);
	(*topb) = sb(topb, false);
	write(1, "ss\n", 3);
}
