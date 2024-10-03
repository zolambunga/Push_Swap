/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:16:25 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/02 16:33:30 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "./libft/libft.h"

t_stack	*create_node(int n)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		exit(1);
	list->nbr = n;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_stack	*recieve_args(int ac, char **args)
{
	int		i;
	t_stack	*new_node;
	t_stack	*head;
	t_stack	*tail;

	head = NULL;
	tail = NULL;
	i = 0;
	while (i < ac)
	{
		new_node = create_node(ft_atoi_sign(args[i]));
		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*tmp;
	t_stack	*a;
	t_stack	*b;

	av = ft_splitmat(av + 1, ' ');
	i = ft_matlen(av);
	ft_verify_args(i, av);
	if (!ft_issorted(av))
		a = recieve_args(i, av);
	printf("\npara tmp\n");                                         tmp = a;                                                        while (tmp)                                                     {                                                                       printf("||%d||\n", tmp->nbr);                                   tmp = tmp->next;                                        }
	ft_free(av, a);
	return (0);
}
