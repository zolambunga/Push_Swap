/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:23 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 20:44:58 by zombunga         ###   ########.fr       */
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
	t_struct	cnt;
	int			triger;

	cnt.i = 0;
	while (av[cnt.i])
	{
		triger = 0;
		cnt.j = 0;
		while (av[cnt.i][cnt.j])
		{
			if ((!ft_isdigit(av[cnt.i][cnt.j])
				&& !ft_issign_space(av[cnt.i][cnt.j]))
				|| (ft_issign(av[cnt.i][cnt.j]) && ft_issign(av[cnt.i][cnt.j
						+ 1])) || (ft_isdigit(av[cnt.i][cnt.j])
					&& ft_issign(av[cnt.i][cnt.j + 1])))
				return (0);
			if (ft_isdigit(av[cnt.i][cnt.j]))
				triger++;
			cnt.j++;
		}
		if (triger == 0)
			return (0);
		cnt.i++;
	}
	return (1);
}

void	ft_verify_args(int ac, char **av, bool freeable)
{
	if (!ft_isvalid(av))
	{
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
