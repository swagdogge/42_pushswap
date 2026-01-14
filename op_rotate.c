/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:47:35 by razimmer          #+#    #+#             */
/*   Updated: 2025/12/12 15:36:26 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	last = stack_last(*s);
	*s = first->next;
	last->next = first;
	first->next = NULL;
}

void	op_ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
