/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:09:08 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 22:37:35 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*ft_sort_two(t_stack *a)
{
	a = ft_sa(&a, true);
	return (a);
}

static t_stack	*ft_sort_three(t_stack *a)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*a3;

	while (!ft_issorted(NULL, a))
	{
		a1 = a;
		a2 = a->next;
		a3 = a->next->next;
		if ((a1->nbr < a2->nbr) && (a2->nbr > a3->nbr) && (a1->nbr < a3->nbr)
			|| ((a1->nbr < a2->nbr) && (a2->nbr > a3->nbr)
				&& (a1->nbr > a3->nbr)))
			a = ft_rra(&a, true);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr)
			&& (a1->nbr > a3->nbr) || ((a1->nbr > a2->nbr)
				&& (a2->nbr > a3->nbr) && (a1->nbr > a3->nbr)))
			a = ft_ra(&a, true);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr)
			&& (a1->nbr < a3->nbr))
			a = ft_sa(&a, true);
	}
	ft_update_index(a, true);
	return (a);
}

static t_stack	*ft_sort_big(t_stack *a, t_stack *b)
{
	ft_send_two_numbers_to_a(&a, &b);
	ft_send_to_b_until_a_is_three(&a, &b);
	a = ft_sort_three(a);
	ft_send_from_b_to_a(&a, &b);
	ft_final_sort(&a);
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
