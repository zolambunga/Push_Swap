/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:46:56 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/25 01:18:05 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_null_target(t_stack *stack)
{
	while (stack)
	{
		stack->target = NULL;
		stack = stack->next;
	}
}

void	ft_update_index(t_stack *stack, bool null_target)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = (ft_lst_size(stack) / 2);
	if (null_target)
		ft_null_target(stack);
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->midpoint_up = true;
		else
			stack->midpoint_up = false;
		stack = stack->next;
		++i;
	}
}
