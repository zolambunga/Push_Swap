/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:53:46 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 18:49:59 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/*static void	ft_swap(t_stack **top)
{
	t_stack	*second;

	second = (*top)->next;
	(*top)->prev = second;
	(*top)->next = second->next;
	second->next->prev = (*top);
	second->prev = NULL;
	second->next = (*top);
	(*top) = second;
}*/

static void	ft_swap(t_stack **top)
{
	t_stack	*second;

	if (!(*top) || !(*top)->next)
		return ;
	second = (*top)->next;
	(*top)->prev = second;
	(*top)->next = second->next;
	if (second->next)
		second->next->prev = (*top);
	second->prev = NULL;
	second->next = (*top);
	(*top) = second;
}

t_stack	*ft_sa(t_stack **top, bool print)
{
	ft_swap(top);
	if (print)
		write(1, "sa\n", 3);
	return (*top);
}

t_stack	*ft_sb(t_stack **top, bool print)
{
	ft_swap(top);
	if (print)
		write(1, "sb\n", 3);
	return (*top);
}

void	ft_ss(t_stack **topa, t_stack **topb)
{
	(*topa) = ft_sa(topa, false);
	(*topb) = ft_sb(topb, false);
	write(1, "ss\n", 3);
}
