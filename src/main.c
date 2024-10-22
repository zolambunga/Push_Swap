/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:16:25 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/22 16:50:13 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(int n)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		exit(1);
	list->nbr = n;
	list->same = false;
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
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_verify_args((ac + 1), (av+1), false);
	av = ft_splitmat(av + 1, ' ');
	i = ft_matlen(av);
	ft_verify_args(i, av, true);
	if (!ft_thereis_duplicate(av) && !ft_issorted(av, NULL))
	{
		a = recieve_args(i, av);
		a = ft_sort(a, b, i);
	}
	ft_free(av, a);
	//ft_free(NULL, b);
	return (0);
}
