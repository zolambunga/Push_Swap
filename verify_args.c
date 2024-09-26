/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:23 by zombunga          #+#    #+#             */
/*   Updated: 2024/09/26 14:16:14 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	ft_isnvalid(int c)
{
	if ((c >= 58) || (c <= 31) || c == 33 || c == 44 || c == 46 || c == 47)
		return (1);
	return (0);
}

char	**ft_verify_args(char **av)
{
	int	i;
	int	j;
	//char	**mat;
	
	i = 0;
	j = 0;
	while (av[i])
	{
		av = ft_split(av[i], ' ');
		i++;
	}
	i = 0;
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
