/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:16:25 by zombunga          #+#    #+#             */
/*   Updated: 2024/09/27 14:05:06 by zombunga         ###   ########.fr       */
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
	i = 1;
	while (i <= ac)
	{
		new_node = create_node(atoi(args[i]));
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
	t_stack	*a;
	t_stack	*b;

	i = ac - 1;
	av = ft_verify_args(ac, av + 1);
	printf("\nsaiu");
	if (!is_sorted(av))
	{
		printf("IS_NOT_SORTED!");
		a = recieve_args(i, av);
	}
	i = 0;
	while (i < 6)
	{
		printf("||%d||\n", a->nbr);
		a = a->next;
		i++;
	}
	return (0);
}
