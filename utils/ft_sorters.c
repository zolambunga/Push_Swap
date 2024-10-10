/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:09:08 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/10 12:23:10 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*ft_sort_three(t_stack *list)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*a3;

	a1 = list;
	a2 = list->next;
	a3 = list->next->next;
	//printf("a1 = %d\n", a1->nbr);
	//printf("a2 = %d\n", a2->nbr);
	//printf("a3 = %d\n", a3->nbr);
	while (!ft_issorted(NULL, list))
	{
		if ((a1->nbr < a2->nbr) && ( a2->nbr > a3->nbr) && (a1->nbr < a3->nbr))
			write(1, "!rra\n", 5);//	rra(list);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr) && (a1->nbr > a3->nbr))
			ra(&list);
		else if ((a1->nbr > a2->nbr) && (a2->nbr > a3->nbr) && (a1->nbr > a3->nbr))
			write(1, "!sa\n", 4); //	sa(list);
		else if ((a1->nbr > a2->nbr) && (a2->nbr < a3->nbr) && (a1->nbr < a3->nbr))
			write(1, "!rra\n", 5);//	rra(list);	
	//	printf("\033[32mWhile, Louco\n\033[0m");
	}
	//printf("\033[35mlist->nbr = %d\033[0m\n", list->nbr);
	//printf("\033[34mlist->next->nbr = %d\033[0m\n", list->next->nbr);
	//printf("\033[36mlist->next->next->nbr = %d\033[0m\n", list->next->next->nbr);
}

void	ft_sort(t_stack *a, t_stack *b, int ac)
{
	if (ac == 3)
		ft_sort_three(a);
	return ;
}
