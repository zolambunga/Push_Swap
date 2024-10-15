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

#include "../includes/push_swap.h"

static t_stack	*ft_sort_two(t_stack *list)
{
	list = sa(&list);
	return (list);
}

static t_stack	*ft_sort_three(t_stack *list)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*a3;

	int i = 0;
	a1 = list;
	a2 = list->next;
	a3 = list->next->next;
	//printf("a1 = %d\n", a1->nbr);
	//printf("a2 = %d\n", a2->nbr);
	//printf("a3 = %d\n", a3->nbr);
	while (!ft_issorted(NULL, list) /*&& (i < 2)*/)
	{
		a1 = list;
		a2 = list->next;
		a3 = list->next->next;
		if ((a1->nbr < a2->nbr) && (a2->nbr > a3->nbr) && (a1->nbr < a3->nbr))
			list = rra(&list);
		else if ((a1->nbr < a2->nbr) && (a2->nbr > a3->nbr) && (a1->nbr > a3->nbr))
			list = rra(&list);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr) && (a1->nbr > a3->nbr))
			list = ra(&list);
		else if ((a1->nbr > a2->nbr) && (a2->nbr > a3->nbr) && (a1->nbr > a3->nbr))
			list = ra(&list);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr) && (a1->nbr < a3->nbr))
			list = sa(&list);
		i++;
	}
	/*printf("\033[35mlist->nbr = %d\033[0m\n", list->nbr);
	printf("\033[34mlist->next->nbr = %d\033[0m\n", list->next->nbr);
	printf("\033[36mlist->next->next->nbr = %d\033[0m\n", list->next->next->nbr);
	printf("\033[37mlist->next->next->next = %p\033[0m\n", list->next->next->next);*/
	return (list);
}

t_stack	*ft_sort(t_stack *a, t_stack *b, int ac)
{
	if (ac == 2)
		a = ft_sort_two(a);
	else if (ac == 3)
		a = ft_sort_three(a);
	return (a);
}
