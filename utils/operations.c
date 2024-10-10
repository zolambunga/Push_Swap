/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:20:07 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/10 12:17:11 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **list)
{
	t_stack *last;
//	t_stack	*tmp;

	//printf("Antes, mas já entrei\n");
	last = ft_lst_findlast(*list);
	//printf("O primeiro é: %d\n", (*list)->nbr);
	//printf("O do meio agora é: %d\n", (*list)->next->nbr);
	//printf("O último é: %d\n", last->nbr);
	(*list)->prev = last;
	//printf("O do meio agora é: %d\n", (*list)->prev->nbr);
	last->next = (*list);
	(*list) = (*list)->next;
	(*list)->prev = NULL;
	//printf("last->next->nbr = %d", last->next->nbr);
	last->next->next = NULL;

	//tmp = *list;
	//int	i = 0;
	/*while (tmp && i > 4)
	{
		printf("\nHi %d\n", tmp->nbr);
		tmp = tmp->prev;
		i++;
	}*/
	write(1, "ra\n", 3);
}
