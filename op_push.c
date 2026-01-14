/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:59:13 by razimmer          #+#    #+#             */
/*   Updated: 2026/01/10 17:38:00 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

int	op_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
	return (1);
}

int	op_pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
	return (1);
}
