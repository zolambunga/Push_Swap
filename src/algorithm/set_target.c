/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:47 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/25 01:17:59 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_set_a(t_stack *tmpa, t_stack *a, t_stack *b, long int targetnbr)
{
	while (tmpa)
	{
		if (!b->target && (b->nbr > (ft_findmax(a))->nbr
				|| b->nbr < (ft_findmin(a))->nbr))
			b->target = ft_findmin(tmpa);
		else if (b->nbr < (ft_findmax(a))->nbr
			&& b->nbr > (ft_findmin(a))->nbr)
		{
			if ((b->nbr < tmpa->nbr) && (ft_abs(b->nbr
						- tmpa->nbr) < targetnbr))
			{
				b->target = tmpa;
				targetnbr = ft_abs(b->nbr - tmpa->nbr);
			}
		}
		tmpa = tmpa->next;
	}
}

void	ft_settarget_b(t_stack *b, t_stack *a)
{
	long int	targetnbr;
	t_stack		*tmpa;

	while (b)
	{
		tmpa = a;
		targetnbr = LONG_MAX;
		ft_set_a(tmpa, a, b, targetnbr);
		b = b->next;
	}
}

static void	ft_set_b(t_stack *tmpb, t_stack *a, t_stack *b, long int targetnbr)
{
	while (tmpb)
	{
		if (!a->target && (a->nbr > (ft_findmax(b))->nbr
				|| a->nbr < (ft_findmin(b))->nbr))
			a->target = ft_findmax(tmpb);
		else if (a->nbr < (ft_findmax(b))->nbr
			&& a->nbr > (ft_findmin(b))->nbr)
		{
			if ((a->nbr > tmpb->nbr) && (ft_abs(a->nbr
						- tmpb->nbr) < targetnbr))
			{
				a->target = tmpb;
				targetnbr = ft_abs(a->nbr - tmpb->nbr);
			}
		}
		tmpb = tmpb->next;
	}
}

void	ft_settarget_a(t_stack *a, t_stack *b)
{
	long int	targetnbr;
	t_stack		*tmpb;

	while (a)
	{
		tmpb = b;
		targetnbr = LONG_MAX;
		ft_set_b(tmpb, a, b, targetnbr);
		a = a->next;
	}
}
