/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:07:11 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 20:44:09 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	ft_get_sign(const char *str, int *i)
{
	int	isneg;

	isneg = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			isneg = -1;
		(*i)++;
	}
	return (isneg);
}

long long int	ft_atoll_pushswap(const char *str)
{
	int				i;
	int				isneg;
	long long int	nbr;

	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	isneg = ft_get_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if ((nbr * isneg) > INT_MAX)
			return (nbr * isneg);
		if ((nbr * isneg) < INT_MIN)
			return (nbr * isneg);
	}
	return (nbr * isneg);
}
