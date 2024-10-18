/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:09:08 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/18 11:39:08 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	/*printf("\033[35mlist->nbr = %d\033[0m\n", list->nbr);
	printf("\033[34mlist->next->nbr = %d\033[0m\n", list->next->nbr);
	printf("\033[36mlist->next->next->nbr = %d\033[0m\n", list->next->next->nbr);
	printf("\033[37mlist->next->next->next = %p\033[0m\n", list->next->next->next);*/
	return (list);
}
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
	printf ("\033[36m====pilha b====\033[0m\n");
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf ("\033[36m===============\033[0m\n");
}
/////////////////////////////////||||||||||||||||||\\\\\\\\\\\//

static t_stack	*ft_sort_big(t_stack *a, t_stack *b)
{	
	int			i;

	i = ft_lst_size(a);
	printlist(a, b);
	if (i-- > 3 && !ft_issorted(NULL, a))
		ft_pb(&a, &b);
	printlist(a, b);
	if (i-- > 3 && !ft_issorted(NULL, a))
		ft_pb(&a, &b);
	printlist(a, b);
	while (i-- > 3 && !ft_issorted(NULL, a))
	{
		ft_pb(&a, &b);
	}
	a = ft_sort_three(a);
	printlist(a, b);
	//if (ft_lst_size(b) == 3)
	//{
	//	printf ("\033[1;39mSORTEADO EM BIG b\033[0m\n");
	//	b = ft_sort_three(b);
	//}
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
