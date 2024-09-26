/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:16:25 by zombunga          #+#    #+#             */
/*   Updated: 2024/09/26 13:49:52 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "./libft/libft.h"

typedef struct s_stack{
	int		nbr;
	struct s_stack	*previous;
	struct s_stack	*next;
} t_stack;

t_stack	*create_node(int n)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		exit(1);
	list->nbr = n;
	list->next = NULL;
	list->previous = NULL;
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
			new_node->previous = tail;
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
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	i = ac - 1;
	if (ac == 1)
		return (1);
	av = ft_verify_args(av + 1);
	a = recieve_args(i, av);
	i = 0;
	while (i++)
		free(av[i]);
	while (a != NULL)
	{
		printf("FIM! %d\n", a->nbr);
		last = a;
		a = a->next;
	}
	a = last;
	while (a)
	{
		printf("Reverse! %d\n", a->nbr);
		first = a;
		a = a->previous;
		i--;
	}
	a = first;
	/*while (a != NULL)
	{
		printf("FIM! %d\n", a->nbr);
		last = a;
		a = a->next;
	}*/
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	return (0);
}
