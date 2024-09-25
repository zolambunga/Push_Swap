#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_stack{
	int		nbr;
	struct s_stack	*previous;
	struct s_stack	*next;
} t_stack;

t_stack	*create_node(t_stack *list, int n)
{
	static t_stack	*head;

	list = (t_stack *)malloc(sizeof(t_stack));
	list->nbr = n;
	//list->previous = list;
	list->next = head;
	head = list;
	return (head);
}

t_stack	*recieve_args(int ac, char **args)
{
	int	i;
	t_stack	*list;
	t_stack	*head;

	i = 1;
	while (i <= ac)
	{
		head = create_node(list, atoi(args[i]));
		//printf("A: %d\n", list->nbr);
		//printf("previous actual: %d\n", list->previous->nbr);
		i++;
	}
	/*printf("\nSaída\nValor de i antes do loop: %d\n\n", i);
	while (i > 1)
	{
		printf("entrei no loop [%d]\n", i);
		list = list->previous;
		printf("Prev: %d\n", list->nbr);
		i--;
	}*/
	return (head);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac == 1)
		return (1);
	a = recieve_args((ac - 1), av);
	
	while (a != NULL)
	{
		printf("FIM! %d\n", a->nbr);
		a = a->next;
	}
	
	//printf("FIM2! %d\n", a->nbr);
	return (0);
}
