/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:16:48 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 17:52:24 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nodes(t_stack **a)
{
	t_stack	*biggest_node;

	if (check_if_sorted(*a) == 1)
		return ;
	biggest_node = find_max_node(*a);
	if ((*a)->value == biggest_node->value)
		ra(a, true);
	else if ((*a)->next->value == biggest_node->value)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}

void	min_to_top(t_stack **a)
{
	while ((*a) != find_min_node(*a))
	{
		if ((find_min_node(*a))->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

t_stack	*find_max_node(t_stack *a)
{
	t_stack	*max_node;
	t_stack	*tmp;

	if (!a)
		return (NULL);
	max_node = a;
	tmp = a;
	while (tmp)
	{
		if (tmp->value > max_node->value)
			max_node = tmp;
		tmp = tmp->next;
	}
	return (max_node);
}

t_stack	*find_min_node(t_stack *a)
{
	t_stack	*min_node;
	t_stack	*tmp;
	int		minimum;

	if (!a)
		return (NULL);
	min_node = a;
	tmp = a;
	minimum = INT_MAX;
	while (tmp)
	{
		if (tmp->value < minimum)
		{
			minimum = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}
