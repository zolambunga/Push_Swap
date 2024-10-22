/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:58:02 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/22 18:10:59 by zombunga         ###   ########.fr       */
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
		(*dst)->prev = node;
		*dst = node;
	}
}

void	ft_pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
