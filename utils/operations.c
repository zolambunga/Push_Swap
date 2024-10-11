/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:20:07 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/11 14:19:20 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ra(t_stack **top)
{
	t_stack *bottom;
//	t_stack	*tmp;

	//printf("Antes, mas já entrei\n");
	bottom = ft_lst_findlast(*top);
	//printf("O primeiro é: %d\n", (*top)->nbr);
	//printf("O do meio agora é: %d\n", (*top)->next->nbr);
	//printf("O último é: %d\n", bottom->nbr);
	(*top)->prev = bottom;
	//printf("O do meio agora é: %d\n", (*top)->prev->nbr);
	bottom->next = (*top);
	(*top) = (*top)->next;
	(*top)->prev = NULL;
	//printf("bottom->next->nbr = %d", last->next->nbr);
	bottom->next->next = NULL;

	//tmp = *top;
	//int	i = 0;
	/*while (tmp && i > 4)
	{
		printf("\nHi %d\n", tmp->nbr);
		tmp = tmp->prev;
		i++;
	}*/
	write(1, "ra\n", 3);
//	ft_free(NULL, bottom);
	return (*top);
}
