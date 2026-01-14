/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:52:31 by razimmer          #+#    #+#             */
/*   Updated: 2026/01/10 19:24:17 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648 

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//stack_ops.c
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **lst, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *s);

//op_swap.c
void	op_sa(t_stack **a);
void	op_sb(t_stack **b);
void	op_ss(t_stack **a, t_stack **b);

//op_rotate.c
void	op_ra(t_stack **a);
void	op_rb(t_stack **b);
void	op_rr(t_stack **a, t_stack **b);

//op_rotate_rev.c
void	op_rra(t_stack **a);
void	op_rrb(t_stack **b);
void	op_rrr(t_stack **a, t_stack **b);

//op_push.c
int		op_pb(t_stack **a, t_stack **b);
int		op_pa(t_stack **a, t_stack **b);

//ft_split.c
char	**ft_split(char const *s, char c);

//sort_small.c
void	sort_small(t_stack **a, t_stack **b, int len);

//misc.c
int		ft_atoi(const char *nptr, int *out);
void	index_stack(t_stack *s);
int		is_sorted(t_stack *a);
int		has_duplicates(t_stack *s);
int		ft_strlen(char const *str);

//garbage.c
void	free_stack(t_stack **s);
void	free_split(char	**split);

#endif