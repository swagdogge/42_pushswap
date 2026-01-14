/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_rev.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:47:38 by razimmer          #+#    #+#             */
/*   Updated: 2025/12/12 15:36:22 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	reverse_rotate(t_stack **s)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	before_last = *s;
	last = stack_last(*s);
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *s;
	*s = last;
}

void	op_rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
