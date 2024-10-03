/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:56 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/02 16:04:44 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"

typedef struct s_stack{
	int	nbr;
	struct s_stack *prev;
	struct s_stack *next;
} t_stack;

void		ft_error();
void		ft_free(char **av, t_stack *list);
void		ft_verify_args(int ac, char **av);
int		ft_issorted(char **av);
	
#endif