/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:56 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/24 19:10:00 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack{
	int				nbr;
	int				index;
	int				total_push_cost;
	int				push_cost;
	bool			midpoint_up;
	struct s_stack	*target;
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

void		ft_update_index(t_stack *stack, bool null_target);
void		ft_pushcost(t_stack *a, t_stack *b, int len_a, int len_b);
void		ft_settarget_a(t_stack *a, t_stack *b);
void		ft_settarget_b(t_stack *b, t_stack *a);
void		ft_atob(t_stack **a, t_stack **b);
void		ft_btoa(t_stack **b, t_stack **a);

t_stack		*ft_sort(t_stack *a, t_stack *b, int ac);
t_stack		*ft_ra(t_stack **top, bool print);
t_stack		*ft_rb(t_stack **top, bool print);
t_stack		*ft_rra(t_stack **top, bool print);
t_stack		*ft_rrb(t_stack **top, bool print);
t_stack		*ft_sa(t_stack **top, bool print);
t_stack		*ft_sb(t_stack **top, bool print);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);
t_stack		*ft_findmin(t_stack *stack);
t_stack		*ft_findmax(t_stack *stack);
t_stack		*ft_findmin_cost(t_stack *stack);
t_stack		*ft_lst_findlast(t_stack *stack);

int			ft_abs(int num);
int			ft_isontop(t_stack *node, t_stack *top);
int			ft_lst_size(t_stack *lst);
int			ft_issorted(char **av, t_stack *stack);
int			ft_thereis_duplicate(char **av);
int			ft_issign_space(char sign);
int			ft_isdigit_space(int c);
long long int	ft_atoll_pushswap(const char *str);

#endif
