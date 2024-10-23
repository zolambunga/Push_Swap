/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:24:11 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/23 16:23:59 by zombunga         ###   ########.fr       */
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
	t_stack *tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

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
	int				i = 0;
	int				isneg;
	long long int	nbr = 0;

	while (ft_isspace(str[i]))
		i++;
	isneg = ft_get_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if (nbr * isneg > INT_MAX)
			return (nbr * isneg);
		if (nbr * isneg < INT_MIN)
			return (nbr * isneg);
	}
	return (nbr * isneg);
}
