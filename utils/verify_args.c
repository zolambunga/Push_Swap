/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:23 by zombunga          #+#    #+#             */
/*   Updated: 2024/09/26 19:35:53 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	ft_isnvalid(int c)
{
	if ((c >= 58) || (c <= 31) || c == 33 || c == 44 || c == 46 || c == 47)
		return (1);
	return (0);
}

static void	check_duplicates(char **av, int i, int j)
{
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				ft_error();
			j++;
		}
		i++;
	}
}

char	**ft_verify_args(char **av)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	check_duplicates(av, 0, 0);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isnvalid(av[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
	return (av);
}
