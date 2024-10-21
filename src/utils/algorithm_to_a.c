/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:47 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/21 18:11:32 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

////////////////////////PARA TESTE/////////||||||||||||||||||\\\\\\\\\\\//
static void	printlist(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	tmp = b;
	printf ("\033[35m====pilha b====\033[0m\n");
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf ("\033[35m===============\033[0m\n");
	tmp = a;
	printf ("\033[36m====pilha a====\033[0m\n");
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf ("\033[36m===============\033[0m\n\033[32m---------------\033[0m\n");
}
/////////////////////////////////||||||||||||||||||\\\\\\\\\\\//
static void	ft_null_target(t_stack *stack)
{
	while(stack)
	{
		stack->target = NULL;
		stack = stack->next;
	}
}

void	ft_update_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = (ft_lst_size(stack) / 2);
	ft_null_target(stack);
	while(stack)
	{
		stack->index = i;
		if (i <= median)
			stack->midpoint_up = true;
		else
			stack->midpoint_up = false;
		stack = stack->next;
		++i;
	}
}

void    ft_settarget_a(t_stack *a, t_stack *b)
{
	long int    targetnbr;
	t_stack	*tmpb;
	/*int	max;
	int	min;
	
	max = (ft_findmax(b))->nbr;
	min = (ft_findmin(b))->nbr;*/
	while(a)
	{
		tmpb = b;
		targetnbr = LONG_MAX;
		while(tmpb)
        	{
			printf("\033[31ma->nbr(%d) e a->target(%p)\033[0m\n", a->nbr, a->target);
			if (!a->target && (a->nbr > (ft_findmax(b))->nbr || a->nbr < (ft_findmin(b))->nbr))
			{
				a->target = ft_findmax(tmpb);
				printf("AQUI EM if (a->nbr(%d) > (ft_findmax(tmpb))->nbr(%d) || a->nbr(%d) < (ft_findmin(tmpb))->nbr)(%d)\n", a->nbr, (ft_findmax(tmpb))->nbr, a->nbr, (ft_findmin(tmpb))->nbr);
			}
			else if (a->nbr < (ft_findmax(b))->nbr && a->nbr > (ft_findmin(b))->nbr)
			{
			printf("\033[3;35mENTRAMOS NA SEGUNDA CONDITION e targetnbr(%ld)\n\033[0m", targetnbr);
				if ((a->nbr > tmpb->nbr) && (ft_abs(a->nbr - tmpb->nbr) < targetnbr))
				{
					printf("\033[35mif ( a->nbr(%d) > tmpb->nbr(%d) && ft_abs(a->nbr(%d) - tmpb->nbr(%d))(%d) < targetnbr(%ld))\n\033[0m", a->nbr, tmpb->nbr, a->nbr, tmpb->nbr, ft_abs(a->nbr - tmpb->nbr), targetnbr);
					a->target = tmpb;
					targetnbr = ft_abs(a->nbr - tmpb->nbr);
					//printf("\033[35mft_abs(a->nbr(%d) - tmpb->nbr(%d))(%d)\n\033[0m", a->nbr, tmpb->nbr, ft_abs(a->nbr - tmpb->nbr));
					//targetnbr = b->nbr;
				}
			}
			printf("\033[35mVALOR DE B b->nbr(%d)\n\033[0m", tmpb->nbr);
			if (a->target)
				printf("\033[32mSAINDO DE SETTARGET\nonde a->nbr(%d) a->target->nbr(%d) targetnbr(%ld)\033[0m\n", a->nbr, a->target->nbr, targetnbr);
			else
				printf("\033[32mSAINDO DE SETTARGET\nonde a->nbr(%d) a->target->nbr(%p) targetnbr(%ld)\033[0m\n", a->nbr, a->target, targetnbr);
			tmpb = tmpb->next;
		}
		a = a->next;
	}
}

static int	ft_cost_calculus(t_stack *stack)
{
	int	cost;

	cost = (stack->index - (ft_lst_size(stack)));
	if(!(stack->midpoint_up))
		return(cost);
	else
		return(stack->index);
}

void    ft_pushcost(t_stack *a, t_stack *b/*target*/)
{
	t_stack	*tmpb;
	int	to_bringa;
	int	to_bringb;

	while(a)
	{
		tmpb = b;
		while(tmpb)
		{
			to_bringa = ft_cost_calculus(a);
			//printf("\033[31mdepois do ft_cost_calculus(a);\n\033[0m");
			to_bringb = ft_cost_calculus(a->target);
			//printf("\033[31mdepois do ft_cost_calculus(a->target);\n\033[0m");
			/*if (to_bringa == to_bringb)
				a->same = true;*/
			a->push_cost = to_bringa + to_bringb;
			tmpb = tmpb->next;
		}
		a = a->next;
	}
}
