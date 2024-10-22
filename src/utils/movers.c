/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:50:36 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/22 06:48:38 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

////////////////////////PARA TESTE/////////||||||||||||||||||\\\\\\\\\\\//
static void	printlist(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	tmp = b;
	printf ("\033[35m====pilha b====\033[0m\n");
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf ("\033[35m===============\033[0m\n");
	tmp = a;
	printf ("\033[36m====pilha a====\033[0m\n");
	while (tmp)
	{
		printf("|%d|%d->push_cost(%d)\n", tmp->index, tmp->nbr, tmp->push_cost);
		tmp = tmp->next;
	}
	printf ("\033[36m===============\033[0m\n\033[32m---------------\033[0m\n");
}
/////////////////////////////////||||||||||||||||||\\\\\\\\\\\//

void ft_atob(t_stack **a, t_stack **b)
{
	t_stack *cheap;

	cheap = ft_findmin_cost(*a);
	while (!ft_isontop(cheap, (*a)))
	{
		if (cheap->midpoint_up)
			ft_ra(&cheap, true);
		else
			ft_rra(&cheap, true);
	}

	while (!ft_isontop(cheap->target, (*b)))
	{
		//printf("\033[36mlist->next->next->nbr = %d\033[0m\n", list->next->next->nbr);
		if (cheap->target->midpoint_up)
			ft_rb(b, true);
		else
			ft_rrb(b, true);
	}
		ft_pb(a, b);

    printlist(*a, *b);
    printf("\033[41mcheap->nbr(%d) (*a)->nbr(%d) (*a)->target->nbr(%d) (*a)->push_cost(%d)|(*b)->nbr(%d) (*b)->push_cost(%d)\033[0m\n\n", cheap->nbr,(*a)->nbr, (*a)->target->nbr, (*a)->push_cost, (*b)->nbr, (*b)->push_cost);
}

void    ft_btoa(t_stack **b, t_stack **a)
{
	t_stack	*cheap;

	cheap = ft_findmin_cost(*b);

    if (!ft_isontop(cheap, (*b)))
    {
            if (cheap->midpoint_up)
                ft_rb(b, true);
            else
                ft_rrb(b, true);
    }
    if (!ft_isontop(cheap->target, (*a)))
    {
            if (cheap->target->midpoint_up)
                ft_ra(b, true);
            else
                ft_rra(b, true);
    }
        if (ft_isontop(cheap->target, (*b)))
            ft_pa(b, a);
}