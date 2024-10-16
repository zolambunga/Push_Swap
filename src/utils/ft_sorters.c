/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:09:08 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/11 14:24:53 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*ft_sort_two(t_stack *list)
{
	list = sa(&list, true);
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
			list = rra(&list, true);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr)
			&& (a1->nbr > a3->nbr)
			|| ((a1->nbr > a2->nbr) && (a2->nbr > a3->nbr)
				&& (a1->nbr > a3->nbr)))
			list = ra(&list, true);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr)
			&& (a1->nbr < a3->nbr))
			list = sa(&list, true);
	}
	/*printf("\033[35mlist->nbr = %d\033[0m\n", list->nbr);
	printf("\033[34mlist->next->nbr = %d\033[0m\n", list->next->nbr);
	printf("\033[36mlist->next->next->nbr = %d\033[0m\n", list->next->next->nbr);
	printf("\033[37mlist->next->next->next = %p\033[0m\n", list->next->next->next);*/
	return (list);
}



static t_stack	*ft_sort_big(t_stack *a, t_stack *b)
{	
	int			i;
	t_stack		*tmp;

	i = ft_lst_size(a);
	while (i-- > 3 && !ft_issorted(NULL, a))
	{
		pb(&a, &b);
	}
	if (ft_lst_size(a) == 3)
	{
		//printf ("\033[1;39mSORTEADO EM BIG\033[0m\n");
		a = ft_sort_three(a);
	}
	/*if (ft_lst_size(b) == 3)
	{
		printf ("\033[1;39mSORTEADO EM BIG b\033[0m\n");
		b = ft_sort_three(b);
	}*/
	tmp = b;
	//printf ("=========\n\033[35mpilha b\033[0m\n");
	while (tmp)
	{
		//printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_free(NULL, b);
	//printf("=========\n\033[36mpilha a\033[0m\n");
	tmp = a;
	while (tmp)
	{
		//printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
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
