/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:56 by zombunga          #+#    #+#             */
/*   Updated: 2024/09/27 16:30:41 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stack{
	int	nbr;
	struct s_stack *prev;
	struct s_stack *next;
} t_stack;

void		ft_error();
void		ft_free(char **av, t_stack *list);
char		**ft_split(char const *s, char c);
char		**ft_verify_args(int ac, char **av);
int		is_not_sorted(char **av);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
	
#endif
