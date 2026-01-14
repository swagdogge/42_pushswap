/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:34:31 by razimmer          #+#    #+#             */
/*   Updated: 2026/01/10 18:48:33 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *nptr, int *out)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	if (!nptr || !nptr[0])
		return (0);
	sign = 1 - 2 * (nptr[i] == '-');
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (nptr[i] == '\0')
		return (0);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (0);
		res = res * 10 + (nptr[i] - 48);
		if (((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN)))
			return (0);
		i++;
	}
	return (*out = (res * sign), 1);
}

void	index_stack(t_stack *s)
{
	int		index;
	t_stack	*current;
	t_stack	*compared;

	current = s;
	while (current)
	{
		compared = s;
		index = 0;
		while (compared)
		{
			if (current->value > compared->value)
				index++;
			compared = compared->next;
		}
		current->index = index;
		current = current->next;
	}	
}

int	is_sorted(t_stack *a)
{
	t_stack	*cur;

	if (!a || !a->next)
		return (1);
	cur = a;
	while (cur->next)
	{	
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	has_duplicates(t_stack *s)
{
	t_stack	*i;
	t_stack	*j;

	i = s;
	while (i)
	{
		j = i-> next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
