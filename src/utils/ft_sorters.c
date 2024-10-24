/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:09:08 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 20:51:08 by zombunga         ###   ########.fr       */
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
		if ((a1->nbr < a2->nbr) && (a2->nbr > a3->nbr) && (a1->nbr < a3->nbr)
			|| ((a1->nbr < a2->nbr) && (a2->nbr > a3->nbr)
				&& (a1->nbr > a3->nbr)))
			list = ft_rra(&list, true);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr)
			&& (a1->nbr > a3->nbr) || ((a1->nbr > a2->nbr)
				&& (a2->nbr > a3->nbr) && (a1->nbr > a3->nbr)))
			list = ft_ra(&list, true);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr)
			&& (a1->nbr < a3->nbr))
			list = ft_sa(&list, true);
	}
	ft_update_index(list, true);
	return (list);
}

static t_stack	*ft_sort_big(t_stack *a, t_stack *b)
{
	if (ft_lst_size(a) != 3 && !ft_issorted(NULL, a))
		ft_pb(&a, &b);
	if (ft_lst_size(a) != 3 && !ft_issorted(NULL, a))
		ft_pb(&a, &b);
	while (ft_lst_size(a) != 3 && !ft_issorted(NULL, a))
	{
		ft_update_index(b, true);
		ft_update_index(a, true);
		ft_settarget_a(a, b);
		ft_pushcost(a, b, ft_lst_size(a), ft_lst_size(b));
		ft_atob(&a, &b);
	}
	a = ft_sort_three(a);
	while (b)
	{
		ft_update_index(a, true);
		ft_update_index(b, true);
		ft_settarget_b(b, a);
		ft_btoa(&b, &a);
	}
	while (!ft_issorted(NULL, a))
	{
		if ((ft_findmin(a))->midpoint_up)
			ft_ra(&a, true);
		else
			ft_rra(&a, true);
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
