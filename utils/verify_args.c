/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:23 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/02 16:23:53 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_issorted(char **av)
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
			if (ft_atoi_sign(av[i]) > ft_atoi_sign(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	ft_free(av, NULL);
	exit(0);
}

static int	ft_isin_accepted_nbrrange(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoll_sign(av[i]) > INT_MAX || ft_atoll_sign(av[i]) < INT_MIN)
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
	j = 0;
	while (av[i])
	{
		triger = 0;
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '+' && av[i][j] != '-')
				return (0);
			if (ft_isdigit(av[i][j]))
				triger++;
			j++;
		}
		if (triger == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_thereis_duplicate(char **av, int i, int j)
{
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_verify_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!ft_isvalid(av))
		ft_error();
	if(!ft_isin_accepted_nbrrange(av))
		ft_error();
	if (ac == 0 || ac == 1)
		exit(0);
	if (ft_thereis_duplicate(av, 0, 0))
		ft_error();
}
