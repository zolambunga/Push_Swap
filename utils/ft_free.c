/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:52:39 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/01 10:52:54 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
void	ft_free(char **av, t_stack *list)
{
	int	i;
	t_stack *aux;

	i = 0;
	printf("\033[32m\nComecei o free\n\033[0m");
	while (av[i])
	{
		printf("free(av[%d])\n", i);
		printf("%s\n", av[i]);
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
