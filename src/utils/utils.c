/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:24:11 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 20:08:11 by zombunga         ###   ########.fr       */
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
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
