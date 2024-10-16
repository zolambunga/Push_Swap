/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:52:39 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/11 14:47:00 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free(char **av, t_stack *list)
{
	//printf("|ft_free|\n");
	int		i;
	t_stack	*aux;

	i = 0;
	//printf("|/em av\\|\n");
	while ((av != NULL) && (av[i] != NULL))
	{
	//	printf("|fazendo free de av[%d]=|%s||\n", i, av[i]);
		free(av[i]);
		i++;
	}
	free(av);
	//printf("\n|/em list\\|\n|");
	while (list != NULL)
	{
	//	printf("|fazendo free de list->next->nbr=|%d||\n", list->nbr);
		aux = list->next;
		free(list);
		list = aux;
	}
}
