/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:47 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/19 17:18:02 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

////////////////////////PARA TESTE/////////||||||||||||||||||\\\\\\\\\\\//                                  

static void     printlist(t_stack *a, t_stack *b)
{
        t_stack         *tmp;                                                                                       tmp = b;                                              printf ("\033[35m====pilha b====\033[0m\n");          while (tmp)                                           {                                                             printf("%d\n", tmp->nbr);                             tmp = tmp->next;                              }                                                     printf ("\033[35m===============\033[0m\n");          tmp = a;                                              printf ("\033[36m====pilha a====\033[0m\n");          while (tmp)                                           {                                                             printf("%d\n", tmp->nbr);                             tmp = tmp->next;                              }                                                     printf ("\033[36m===============\033[0m\n\033[32m---------------\033[0m\n");                        }                                                     /////////////////////////////////||||||||||||||||||\\\\\\\\\\\//

void	ft_update_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = (ft_lst_size(stack) / 2);
	//ft_pushcost(stack, stack->target);
	while (stack)
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

    tmpb = b;
    targetnbr = LONG_MAX;
    while(a)
    {
        b = tmpb;
        while(b)
        {
            if (a->nbr > (ft_findmax(b))->nbr
                || a->nbr < (ft_findmin(b))->nbr)
                a->target = ft_findmax(b);
            else if(a->nbr < (ft_findmax(b))->nbr
                && a->nbr > (ft_findmin(b))->nbr)
            {
                if (ft_abs(a->nbr - b->nbr) < targetnbr)
                {
                    a->target = b;
                    targetnbr = b->nbr;
                }
            }
            b = b->next;
        }
        a = a->next;
    }
}

static int ft_cost_calculus(t_stack *stack)
{
    int cost;

    cost = (stack->index - (ft_lst_size(stack)));
    printf("em ft_cost_calculus(t_stack *stack)\nonde stack->nbr(%d) stack->index(%d)\n", stack->nbr, stack->index);
   printlist(stack, NULL);
    if(!(stack->midpoint_up))
        return(cost);
    else
        return(stack->index);
}

void    ft_pushcost(t_stack *a, t_stack *b/*target*/)
{
    t_stack *tmpb;
    int to_bringa;
    int to_bringb;

    while(a)
    {
        tmpb = b;
        while(tmpb)
        {
            to_bringa = ft_cost_calculus(a);
	    printf("\033[31mdepois do ft_cost_calculus(a);\n\033[0m");
            to_bringb = ft_cost_calculus(a->target);
	    printf("\033[31mdepois do ft_cost_calculus(a->target);\n\033[0m");
            a->push_cost = to_bringa + to_bringb;
            tmpb = tmpb->next;
        }
        a = a->next;
    }
}
	//printf("\033[36mlist->next->next->nbr = %d\033[0m\n", list->next->next->nbr);
