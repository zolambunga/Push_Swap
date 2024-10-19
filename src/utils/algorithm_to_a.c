/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:47 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/19 17:18:02 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_update_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = (ft_lst_size(stack) / 2);
    ft_pushcost(stack, stack->target);
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

void    ft_settarget_a(t_stack *a, t_stack *b)
{
    long int    targetnbr;

    targetnbr = LONG_MAX;
    while(a)
    {
        
        while(b)
        {
            if (a->nbr > (ft_findmax(b))->nbr
                || a->nbr < (ft_findmin(b))->nbr)
                a->target = ft_findmax(b);
            else if(a->nbr < (ft_findmax(b))->nbr
                && a->nbr > (ft_findmin(b))->nbr)
            {
                if (ft_abs(a->nbr - b->nbr) < targetnbr)
                {
                    a->target = b;
                    targetnbr = b->nbr;
                }
            }
            b = b->next;
        }
        a = a->next;
    }
}

static int ft_cost_calculus(t_stack *stack)
{
    int cost;

    cost = (stack->index - (ft_lst_size(stack)));
    if(!(stack->midpoint_up))
        return(cost);
    else
        return(stack->index);
}

void    ft_pushcost(t_stack *a, t_stack *b)
{
    t_stack *tmpb;
    int to_bringa;
    int to_bringb;

    while(a)
    {
        tmpb = b;
        while(tmpb)
        {
            to_bringa = ft_cost_calculus(a);
            to_bringb = ft_cost_calculus(a->target);
            a->push_cost = to_bringa + to_bringb;
            tmpb = tmpb->next;
        }
        a = a->next;
    }
}
