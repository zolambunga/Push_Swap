/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:56 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/11 14:25:56 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_struct{
	int	i;
	int	j;
}	t_struct;

t_stack		*ft_sort(t_stack *a, t_stack *b, int ac);
void		ft_error(void);
void		ft_verify_args(int ac, char **av);
void		ft_free(char **av, t_stack *list);
t_stack		*ra(t_stack **top);

int			ft_issorted(char **av, t_stack *list);
int			ft_thereis_duplicate(char **av);


t_stack		*ft_lst_findlast(t_stack *list);

#endif
