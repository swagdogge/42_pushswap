/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:23:44 by razimmer          #+#    #+#             */
/*   Updated: 2026/01/10 18:50:27 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc((sizeof(*node)));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*curr;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr-> next != NULL)
		curr = curr->next;
	curr->next = new;
}

t_stack	*stack_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

int	stack_size(t_stack *s)
{
	int		c;
	t_stack	*current;

	c = 0;
	current = s;
	while (current)
	{
		current = current->next;
		c++;
	}
	return (c);
}
