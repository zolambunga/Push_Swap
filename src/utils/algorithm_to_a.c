/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:47 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 14:44:19 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

////////////////////////PARA TESTE/////////||||||||||||||||||\\\\\\\\\\\//
static void	printlist(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	tmp = b;
	//printf ("\033[35m====pilha b====\033[0m\n");
	while (tmp)
	{
	//	printf("[%d]%d->push_cost(%d)\n", tmp->index, tmp->nbr, tmp->push_cost);
		tmp = tmp->next;
	}
	//printf ("\033[35m===============\033[0m\n");
	tmp = a;
	//printf ("\033[36m====pilha a====\033[0m\n");
	while (tmp)
	{
	//printf("[%d]%d->push_cost(%d)\n", tmp->index, tmp->nbr, tmp->push_cost);
		tmp = tmp->next;
	}
	//printf ("\033[36m===============\033[0m\n\033[32m---------------\033[0m\n");
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

void	ft_update_index(t_stack *stack, bool null_target)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = (ft_lst_size(stack) / 2);
	if (null_target)
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

void	ft_settarget_a(t_stack *a, t_stack *b)
{
	long int	targetnbr;
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
			//printf("\033[31ma->nbr(%d) e a->target(%p)\033[0m\n", a->nbr, a->target);
			if (!a->target && (a->nbr > (ft_findmax(b))->nbr || a->nbr < (ft_findmin(b))->nbr))
			{
				a->target = ft_findmax(tmpb);
				//printf("AQUI EM if (a->nbr(%d) > (ft_findmax(tmpb))->nbr(%d) || a->nbr(%d) < (ft_findmin(tmpb))->nbr)(%d)\n", a->nbr, (ft_findmax(tmpb))->nbr, a->nbr, (ft_findmin(tmpb))->nbr);
			}
			else if (a->nbr < (ft_findmax(b))->nbr && a->nbr > (ft_findmin(b))->nbr)
			{
			//printf("\033[3;35mENTRAMOS NA SEGUNDA CONDITION e targetnbr(%ld)\n\033[0m", targetnbr);
				if ((a->nbr > tmpb->nbr) && (ft_abs(a->nbr - tmpb->nbr) < targetnbr))
				{
			//		printf("\033[35mif ( a->nbr(%d) > tmpb->nbr(%d) && ft_abs(a->nbr(%d) - tmpb->nbr(%d))(%d) < targetnbr(%ld))\n\033[0m", a->nbr, tmpb->nbr, a->nbr, tmpb->nbr, ft_abs(a->nbr - tmpb->nbr), targetnbr);
					a->target = tmpb;
					targetnbr = ft_abs(a->nbr - tmpb->nbr);
				//	printf("\033[35mft_abs(a->nbr(%d) - tmpb->nbr(%d))(%d)\n\033[0m", a->nbr, tmpb->nbr, ft_abs(a->nbr - tmpb->nbr));
					//targetnbr = b->nbr;
				}
			}
		//	printf("\033[35mVALOR DE B b->nbr(%d)\n\033[0m", tmpb->nbr);
			//if (a->target)
		//		printf("\033[32mSAINDO DE SETTARGET\nonde a->nbr(%d) a->target->nbr(%d) targetnbr(%ld)\033[0m\n", a->nbr, a->target->nbr, targetnbr);
		//	else
		//		printf("\033[32mSAINDO DE SETTARGET\nonde a->nbr(%d) a->target->nbr(%p) targetnbr(%ld)\033[0m\n", a->nbr, a->target, targetnbr);
			tmpb = tmpb->next;
		}
		a = a->next;
	}
}

void	ft_settarget_b(t_stack *b, t_stack *a)
{
	long int	targetnbr;
	t_stack	*tmpa;

	while(b)
	{
		tmpa = a;
		targetnbr = LONG_MAX;
		while(tmpa)
		{
			//printf("\033[31mb->nbr(%d) e b->target(%p)\033[0m\n", b->nbr, b->target);
			if (!b->target && (b->nbr > (ft_findmax(a))->nbr || b->nbr < (ft_findmin(a))->nbr))
			{
				b->target = ft_findmin(tmpa);
			//	printf("AQUI EM if (a->nbr(%d) > (ft_findmax(tmpa))->nbr(%d) || a->nbr(%d) < (ft_findmin(tmpa))->nbr)(%d)\n", a->nbr, (ft_findmax(tmpa))->nbr, a->nbr, (ft_findmin(tmpa))->nbr);
			}
			else if (b->nbr < (ft_findmax(a))->nbr && b->nbr > (ft_findmin(a))->nbr)
			{
			//printf("\033[3;35mENTRAMOS NA SEGUNDA CONDITION e targetnbr(%ld)\n\033[0m", targetnbr);
				if ((b->nbr < tmpa->nbr) && (ft_abs(b->nbr - tmpa->nbr) < targetnbr))
				{
				//	printf("\033[35mif ( a->nbr(%d) > tmpa->nbr(%d) && ft_abs(a->nbr(%d) - tmpa->nbr(%d))(%d) < targetnbr(%ld))\n\033[0m", a->nbr, tmpa->nbr, a->nbr, tmpa->nbr, ft_abs(a->nbr - tmpa->nbr), targetnbr);
					b->target = tmpa;
					targetnbr = ft_abs(b->nbr - tmpa->nbr);
					//printf("\033[35mft_abs(a->nbr(%d) - tmpb->nbr(%d))(%d)\n\033[0m", a->nbr, tmpb->nbr, ft_abs(a->nbr - tmpb->nbr));
					//targetnbr = b->nbr;
				}
			}
			//printf("\033[35mVALOR DE A a->nbr(%d)\n\033[0m", tmpa->nbr);
			//if (b->target)
			//	printf("\033[32mSAINDO DE SETTARGETB\nonde b->nbr(%d) b->target->nbr(%d) targetnbr(%ld)\033[0m\n", b->nbr, b->target->nbr, targetnbr);
			//else
			//	printf("\033[32mSAINDO DE SETTARGETB\nonde b->nbr(%d) b->target->nbr(%p) targetnbr(%ld)\033[0m\n", b->nbr, b->target, targetnbr);
			tmpa = tmpa->next;
		}
		b = b->next;
	}
}

static int	ft_cost_calculus(t_stack *stack, int stack_size)
{
	int	cost;

	cost = (stack_size - stack->index);
	//printf("stack->nbr\033[32m(%d)\033[0m EM COST cost(%d) = (stack_size(%d) - stack->index(%d)) ||", stack->nbr, cost, stack_size, stack->index);
	if (stack->midpoint_up)
	{
	//	printf("\033[31mstack->index(%d)\033[0m\n", stack->index);
		return (stack->index);
	}
	else
	{
		//printf("\033[31mcost(%d)\033[0m\n", cost);
		return (cost);
	}
}

void    ft_pushcost(t_stack *a, t_stack *b, int len_a, int len_b)
{
	t_stack	*tmpb;
	int	to_bringa;
	int	to_bringb;

	while(a)
	{
		tmpb = b;
		/*while(tmpb)
		{*/
			to_bringa = ft_cost_calculus(a, len_a);
			//printf("\033[31mdepois do ft_cost_calculus(a);\n\033[0m");
			to_bringb = ft_cost_calculus(a->target, len_b);
			a->target->push_cost = to_bringb;
			//printf("\033[31mdepois do ft_cost_calculus(a->target);\n\033[0m");
			if (!a->midpoint_up && !a->target->midpoint_up
				&& to_bringa == to_bringb)
			{
				a->same = true;
				a->target->same = true;
				a->push_cost = to_bringa;
			}
			else if (a->midpoint_up && a->target->midpoint_up
				&& to_bringa == to_bringb)
			{
				a->same = true;
				a->target->same = true;
				a->push_cost = to_bringa;
			}
			else
				a->push_cost = to_bringa + to_bringb;
		/*	tmpb = tmpb->next;
		}*/
		a = a->next;
	}
}
