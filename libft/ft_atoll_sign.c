/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 02:30:48 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/03 02:46:41 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	iter_sign(const char *str, int *i)
{
	if (!ft_isdigit(str[*i]))
		while (str[*i] != '\0' && !ft_isdigit(str[*i + 1]))
			*i = *i + 1;
}

long long int	ft_atoll_sign(const char *str)
{
	int		i;
	int		isneg;
	long long int	nbr;

	i = 0;
	nbr = 0;
	isneg = 0;
	iter_sign(str, &i);
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	iter_sign(str, &i);
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}
/*
int main(int ac, char **av)
{
	printf("%lld\n", ft_atoll_sign(av[1]));
	return 0;
}*/
