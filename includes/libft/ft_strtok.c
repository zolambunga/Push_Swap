/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:23:10 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/01 14:15:28 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	char		*start;
	static char	*point;

	if (str)
		point = str;
	if (!point || !*point)
		return (NULL);
	while (*point && ft_strchr(delim, *point))
		point++;
	start = point;
	while (*point && !ft_strchr(delim, *point))
		point++;
	if (*point && ft_strchr(delim, *point))
	{
		*point = '\0';
		point++;
	}
	while (*point && ft_strchr(delim, *point))
		point++;
	if (!*start)
		return (NULL);
	return (start);
}
