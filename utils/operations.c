/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:20:07 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/11 14:19:20 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ra(t_stack **top)
{
	t_stack *bottom;

	bottom = ft_lst_findlast(*top);
	(*top)->prev = bottom;
	bottom->next = (*top);
	(*top) = (*top)->next;
	(*top)->prev = NULL;
	bottom->next->next = NULL;
	write(1, "ra\n", 3);
	return (*top);
}

t_stack	*rra(t_stack **top)
{
	t_stack	*bottom;

	bottom = ft_lst_findlast(*top);
	bottom->next = (*top);
	(*top)->prev = bottom;
	(*top) = bottom;
	bottom->prev->next = NULL;
	write(1, "rra\n", 4);
	return (*top);
}

t_stack	*sa(t_stack **top)
{
	t_stack	*second;

	second = (*top)->next;
	(*top)->prev = second;
	(*top)->next = second->next;
	second->prev = NULL;
	second->next = (*top);
	(*top) = second;
	write(1, "sa\n", 3);
	return (*top);
}
