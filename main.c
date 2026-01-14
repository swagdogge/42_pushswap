/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:58:30 by razimmer          #+#    #+#             */
/*   Updated: 2026/01/10 19:31:49 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

double	ft_sqrt_binary(double n)
{
	double	low;
	double	high;
	double	mid;
	int		i;

	low = 0;
	i = 0;
	high = n;
	while (i < 100)
	{
		mid = (low + high) / 2;
		if (mid * mid > n)
			high = mid;
		else
			low = mid;
		i++;
	}
	return (mid);
}

void	pushback(t_stack **a, t_stack **b, int c)
{
	int		rotates;
	t_stack	*current;

	while (*b)
	{
		if ((*b)->index == c - 1)
			c -= op_pa(a, b);
		else
		{
			rotates = 0;
			current = *b;
			while (current && current->index != (c - 1))
			{
				rotates++;
				current = current->next;
			}
			if (rotates == 1)
				op_sb(b);
			else if (rotates <= stack_size(*b) / 2)
				op_rb(b);
			else
				op_rrb(b);
		}
	}
}

void	ksort(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	range;
	int	rr_opt;

	i = 0;
	range = ft_sqrt_binary(len) * 1.4;
	while (i < len)
	{
		if ((*a)->index <= i)
		{
			rr_opt = 0;
			if ((*a)->next && !((*a)->next->index < i + range))
				rr_opt = 1;
			i += op_pb(a, b);
			if (rr_opt)
				op_rr(a, b);
			else
				op_rb(b);
		}
		else if ((*a)->index < i + range)
			i += op_pb(a, b);
		else
			op_ra(a);
	}
	pushback(a, b, i);
}

static int	handler(t_stack **a, t_stack **b, char **arr)
{
	int	atoi_value;
	int	i;

	atoi_value = 0;
	i = 0;
	while (arr[i])
	{
		if (!ft_atoi(arr[i], &atoi_value))
			return (write(2, "Error\n", 6), 1);
		stack_add_back(a, stack_new(atoi_value));
		i++;
	}
	if (has_duplicates (*a))
		return (write(2, "Error\n", 6), 1);
	index_stack(*a);
	if (is_sorted(*a))
		return (0);
	if (stack_size(*a) <= 5)
		sort_small(a, b, stack_size(*a));
	else
		ksort(a, b, stack_size(*a));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**wurst;
	int		ret;
	int		splitted;

	a = NULL;
	b = NULL;
	splitted = 0;
	if (argc == 2)
	{
		wurst = ft_split(argv[1], ' ');
		if (!wurst)
			return (0);
		splitted = 1;
	}
	else
		wurst = argv + 1;
	ret = handler (&a, &b, wurst);
	if (splitted)
		free_split(wurst);
	free_stack(&a);
	free_stack(&b);
	return (ret);
}
