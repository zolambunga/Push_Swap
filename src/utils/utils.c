/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:24:11 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/10 12:15:40 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_issign_space(char sign)
{
	return (sign == '+' || sign == '-' || sign == ' ');
}

int	ft_isdigit_space(int c)
{
	return ((c >= '0' && c <= '9') || c == ' ' || c == '\0');
}

t_stack	*ft_lst_findlast(t_stack *list)
{
	t_stack	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_lst_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

long long int	ft_atoll_pushswap(const char *str)
{
	int				i;
	int				isneg;
	long long int	nbr;

	i = 0;
	nbr = 0;
	isneg = 1;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (nbr);
	}
	return (nbr * isneg);
}
