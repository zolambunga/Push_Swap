/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:56 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/18 14:25:12 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
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

void		ft_error(void);
void		ft_verify_args(int ac, char **av, bool freeable);
void		ft_free(char **av, t_stack *list);
void		ft_rrr(t_stack **topa, t_stack **topb);
void		ft_rr(t_stack **topa, t_stack **topb);
void		ft_ss(t_stack **topa, t_stack **topb);

t_stack		*ft_sort(t_stack *a, t_stack *b, int ac);
t_stack		*ft_ra(t_stack **top, bool print);
t_stack		*ft_rb(t_stack **top, bool print);
t_stack		*ft_rra(t_stack **top, bool print);
t_stack		*ft_rrb(t_stack **top, bool print);
t_stack		*ft_sa(t_stack **top, bool print);
t_stack		*ft_sb(t_stack **top, bool print);
t_stack		*ft_pa(t_stack **a, t_stack **b);
t_stack		*ft_pb(t_stack **a, t_stack **b);
t_stack		*ft_atob(t_stack **a, t_stack **b);
t_stack		*ft_findmin(t_stack *list);
t_stack		*ft_findmax(t_stack *list);
t_stack		*ft_lst_findlast(t_stack *list);

int			ft_lst_size(t_stack *lst);
int			ft_issorted(char **av, t_stack *list);
int			ft_thereis_duplicate(char **av);
int			ft_issign_space(char sign);
int			ft_isdigit_space(int c);
long long int	ft_atoll_pushswap(const char *str);

#endif
