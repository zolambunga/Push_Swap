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
	int		i;
	t_stack	*aux;

	i = 0;
	while ((av != NULL) && (av[i] != NULL))
	{
		free(av[i]);
		i++;
	}
	free(av);
	while (list != NULL)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
}
