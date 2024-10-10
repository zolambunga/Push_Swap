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

#include "../includes/push_swap.h"

t_stack	*ft_lst_findlast(t_stack *list)
{
	t_stack	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	//ft_free(NULL, list);
	return (tmp);
}
