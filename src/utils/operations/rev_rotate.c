/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:48:01 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/22 18:14:49 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

////////////////////////PARA TESTE/////////||||||||||||||||||\\\\\\\\\\\//
static void	printlist(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	tmp = b;
	printf ("\033[35m====pilha b====\033[0m\n");
	while (tmp)
	{
		printf("[%d]%d->push_cost(%d)\n", tmp->index, tmp->nbr, tmp->push_cost);
		tmp = tmp->next;
	}
	printf ("\033[35m===============\033[0m\n");
	tmp = a;
	printf ("\033[36m====pilha a====\033[0m\n");
	while (tmp)
	{
		printf("[%d]%d->push_cost(%d)\n", tmp->index, tmp->nbr, tmp->push_cost);
		tmp = tmp->next;
	}
	printf ("\033[36m===============\033[0m\n\033[32m---------------\033[0m\n");
}
/////////////////////////////////||||||||||||||||||\\\\\\\\\\\//

static void	rev_rotate(t_stack **top)
{
	t_stack	*bottom;

	bottom = ft_lst_findlast(*top);
	bottom->next = (*top);
	(*top)->prev = bottom;
	(*top) = bottom;
	printf("bottom->nbr(%d)\n", bottom->nbr);
	printf("bottom->prev->nbr(%d)\n", bottom->prev->nbr);
	printf("bottom->prev->next->nbr(%d)\n", bottom->prev->next->nbr);
	bottom->prev->next = NULL;
	
}

t_stack	*ft_rra(t_stack **top, bool print)
{
	rev_rotate(top);
	if (print)
		write(1, "rra\n", 4);
	printlist(*top, NULL);
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
