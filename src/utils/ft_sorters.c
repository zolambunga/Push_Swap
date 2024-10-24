/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:09:08 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 09:01:58 by zombunga         ###   ########.fr       */
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

static t_stack	*ft_sort_two(t_stack *list)
{
	list = ft_sa(&list, true);
	return (list);
}

static t_stack	*ft_sort_three(t_stack *list)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*a3;

	while (!ft_issorted(NULL, list))
	{
		a1 = list;
		a2 = list->next;
		a3 = list->next->next;
		if ((a1->nbr < a2->nbr) && (a2->nbr > a3->nbr)
			&& (a1->nbr < a3->nbr)
			|| ((a1->nbr < a2->nbr) && (a2->nbr > a3->nbr)
				&& (a1->nbr > a3->nbr)))
			list = ft_rra(&list, true);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr)
			&& (a1->nbr > a3->nbr)
			|| ((a1->nbr > a2->nbr) && (a2->nbr > a3->nbr)
				&& (a1->nbr > a3->nbr)))
			list = ft_ra(&list, true);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr)
			&& (a1->nbr < a3->nbr))
			list = ft_sa(&list, true);
	}
	ft_update_index(list, true);
	//printf("\033[35mlist->nbr = %d\033[0m\n", list->nbr);
	//printf("\033[34mlist->next->nbr = %d\033[0m\n", list->next->nbr);
	//printf("\033[36mlist->next->next->nbr = %d\033[0m\n", list->next->next->nbr);
	//printf("\033[37mlist->next->next->next = %p\033[0m\n", list->next->next->next);
	//t_stack *a;
	//a = list;
	//while(a)
	//{

	//	printf("a->nbr(%d)\n", a->nbr);	
	//	if(!a->next)
	//	{
	//		break;
	//	}
	//	a = a->next;
	//}
	//while(a)
	//{
	//	printf("HOLEE a->nbr(%d)\n", a->nbr);
	//	a = a->prev;
	//}
	//printf("\033[37mlist->next->next->next = %p\033[0m\n", list->next->next->next);
	//}
	//printlist(NULL, list);
	return (list);
}

static t_stack	*ft_sort_big(t_stack *a, t_stack *b)
{	
	int			i;

	i = ft_lst_size(a);
	//printf("valor de i = %d\n", i);
	//printlist(a, b);
	if (ft_lst_size(a) != 3 && !ft_issorted(NULL, a))
		ft_pb(&a, &b);
	//printf("valor de i = %d\n", i);
	//printlist(a, b);
	if (ft_lst_size(a) != 3 && !ft_issorted(NULL, a))
		ft_pb(&a, &b);
	//printf("valor de i = %d\n", i);
	printlist(a, b);
	//printf("estou a ir ao while, onde\nwhile (i(%d)-- > 3 && !ft_issorted(NULL, a))\n", i);
	while (ft_lst_size(a) != 3 && !ft_issorted(NULL, a))
	{
		ft_update_index(b, true);
		ft_update_index(a, true);
		ft_settarget_a(a, b);
		ft_pushcost(a, b, ft_lst_size(a), ft_lst_size(b));
		printlist(a, b);
		printf("==============================\n");
		ft_atob(&a, &b);
		//ft_update_index(b);
		//ft_update_index(a);
		printlist(a, b);
		printf("valor de i aqui dentro = %d\n", i);
	}
		a = ft_sort_three(a);
		ft_update_index(a, true);
		ft_update_index(b, true);
		printlist(a, b);
	while (b)
	{
		ft_update_index(a, true);
		ft_update_index(b, true);
		printlist(a, b);
		ft_settarget_b(b, a);
		//ft_pushcost(a, b);
		
		ft_btoa(&b, &a);
		printlist(a, b);
		//printf("valor de i aqui dentro = %d\n", i);
	}
	while(!ft_issorted(NULL, a))
		ft_rra(&a, true);
	//ft_update_index(a);
	printlist(a, b);
	return (a);
}

t_stack	*ft_sort(t_stack *a, t_stack *b, int ac)
{
	if (ac == 2)
		a = ft_sort_two(a);
	else if (ac == 3)
		a = ft_sort_three(a);
	else if (ac > 3)
		a = ft_sort_big(a, b);
	return (a);
}
