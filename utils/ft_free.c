/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:52:39 by zombunga          #+#    #+#             */
/*   Updated: 2024/09/27 16:32:41 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **av, t_stack *list)
{
	int	i;
	t_stack *aux;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	while(list)
	{
		aux = list->next;
		free (list);
		list = aux;
	}
}
