/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:23 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/19 16:41:54 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_thereis_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_free(av, NULL);
				ft_error();
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_issorted(char **av, t_stack *stack)
{
	t_stack		*tmp;
	t_struct	iter;

	iter.i = 0;
	iter.j = 0;
	tmp = stack;
	while (av != NULL && av[iter.i])
	{
		iter.j = iter.i + 1;
		while (av[iter.j])
		{
			if (ft_atoi(av[iter.i]) > ft_atoi(av[iter.j]))
				return (0);
			iter.j++;
		}
		iter.i++;
	}
	while (tmp != NULL && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_isin_accepted_nbrrange(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoll_pushswap(av[i]) > INT_MAX
			|| ft_atoll_pushswap(av[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isvalid(char **av)
{
	int	i;
	int	j;
	int	triger;

	i = 0;
	while (av[i])
	{
		triger = 0;
		j = 0;
		while (av[i][j])
		{
			//printf("av[i][j] = |%c|\nav[i][j+1] = |%c|\n", av[i][j], av[i][j+1]);
			if ((!ft_isdigit(av[i][j]) && !ft_issign_space(av[i][j]))
			|| (!ft_isdigit(av[i][j]) && !ft_isdigit_space(av[i][j + 1]))
			|| (ft_isdigit(av[i][j]) && ft_issign(av[i][j + 1])))
				return (0);
			if (ft_isdigit(av[i][j]))
				triger++;
			j++;
		}
		if (triger == 0)
		{
			printf("triger é %d\n", triger);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_verify_args(int ac, char **av, bool freeable)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!ft_isvalid(av))
	{
		//printf("invalid\n");
		if (freeable)
			ft_free(av, NULL);
		ft_error();
	}
	if (!ft_isin_accepted_nbrrange(av))
	{
		if (freeable)
			ft_free(av, NULL);
		ft_error();
	}
	if (ac == 0 || ac == 1)
	{
		if (freeable)
			ft_free(av, NULL);
		exit(0);
	}
}
