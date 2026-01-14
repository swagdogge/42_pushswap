/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:26:29 by razimmer          #+#    #+#             */
/*   Updated: 2026/01/10 18:52:05 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	int	find_min_pos(t_stack **a)
{
	t_stack	*p;
	int		i;
	int		min;
	int		pos;

	p = *a;
	i = 0;
	min = p->value;
	pos = 0;
	while (p)
	{
		if (p->value < min)
		{
			min = p->value;
			pos = i;
		}
		p = p->next;
		i++;
	}
	return (pos);
}

static	void	min_to_b(t_stack **a, t_stack **b, int num)
{
	int	pos;

	pos = find_min_pos(a);
	if (pos <= num / 2)
		while (pos--)
			op_ra(a);
	else
		while (pos++ < num)
			op_rra(a);
	op_pb(a, b);
}

static	int	sort_three(t_stack **a)
{
	int	e_1;
	int	e_2;
	int	e_3;

	e_1 = (*a)->value;
	e_2 = (*a)->next->value;
	e_3 = (*a)->next->next->value;
	if (e_1 < e_2 && e_2 < e_3)
		return (1);
	if (e_1 > e_2 && e_2 < e_3 && e_1 < e_3)
		return (op_sa(a), 1);
	if (e_1 > e_2 && e_2 < e_3 && e_1 > e_3)
		return (op_ra(a), 1);
	if (e_1 < e_2 && e_2 > e_3 && e_1 > e_3)
		return (op_rra(a), 1);
	if (e_1 < e_2 && e_2 > e_3 && e_1 < e_3)
		return (op_sa(a), op_ra(a), 1);
	return (op_sa(a), op_rra(a), 1);
}

static	void	sort_four_or_five(t_stack **a, t_stack **b, int num)
{
	min_to_b(a, b, num);
	if (num == 5)
		min_to_b(a, b, num - 1);
	sort_three(a);
	if (num == 5 && (*b)->value < (*b)->next->value)
		op_sb(b);
	op_pa(a, b);
	if (num == 5)
		op_pa(a, b);
}

void	sort_small(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
		op_sa(a);
	else if (len == 3)
		sort_three(a);
	else
		sort_four_or_five(a, b, len);
}
