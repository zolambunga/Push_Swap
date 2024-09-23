/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:52:37 by zombunga          #+#    #+#             */
/*   Updated: 2024/09/23 15:29:29 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
//#include <>

typedef struct s_node
{
	int		nbr;
	struct s_node	*next;
} t_node;

t_node	*create_node(int n)
{
	t_node *new_node;
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->nbr = n;
	new_node->next = NULL;
	return(new_node);
}

t_node	*recieve_args(int ac, char **av)
{
	int	i;
	t_node	*new_node;
	t_node	*head;

	i = 1;
	//head = new_node;
	head = create_node(atoi(av[i]));
	while (i <= ac)
	{
		new_node = create_node(atoi(av[i]));
		printf("Recieve_args: %d\n", new_node->nbr);
		new_node = new_node->next;
		i++;
	}
	printf("\n\n");
	return (head);
}

int	main(int ac, char **av)
{
	t_node *a;
	if (ac == 1)
		return (1);
	//verify_args(av);
	a = recieve_args((ac - 1), av);

	while (a)
	{
		printf("A: %d\n", a->nbr);
		a = a->next;
	}
	/*if (ac <= 3)
	{
		
	}*/
}
