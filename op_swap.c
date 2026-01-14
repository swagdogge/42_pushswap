/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:47:33 by razimmer          #+#    #+#             */
/*   Updated: 2025/12/12 15:36:31 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_stack **s)
{
	t_stack	*elem_a;
	t_stack	*elem_b;

	if (!s || !*s || !(*s)->next)
		return ;
	elem_a = *s;
	elem_b = elem_a->next;
	elem_a->next = elem_b->next;
	elem_b->next = elem_a;
	*s = elem_b;
}

void	op_sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	op_sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	op_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
