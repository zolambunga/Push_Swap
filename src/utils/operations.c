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

#include "../../includes/push_swap.h"

static void	rotate(t_stack **top)
{
	t_stack *bottom;

	bottom = ft_lst_findlast(*top);
	(*top)->prev = bottom;
	bottom->next = (*top);
	(*top) = (*top)->next;
	(*top)->prev = NULL;
	bottom->next->next = NULL;
}

t_stack	*ra(t_stack **top)
{
	rotate(top);
	write(1, "ra\n", 3);
	return (*top);
}

t_stack	*rb(t_stack **top)
{
	rotate(top);
	write(1, "rb\n", 3);
	return (*top);
}


//t_stack	*rr(t_stack **top)
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

//////////////////////////////////

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (!*src)
		return ;
	node = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (!*dst)
	{
		*dst = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dst;
		node->next->prev = node;
		*dst = node;
	}
}

t_stack	*pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

t_stack	*pb(t_stack **a, t_stack **b)
{
	push(b, a); 
	write(1, "pb\n", 3);
}


