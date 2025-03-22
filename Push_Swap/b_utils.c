/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:37:43 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/02 16:46:50 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_node_for_b(t_stack *a, t_stack *b)
{
	t_stack		*current_a_node;
	t_stack		*target_node;
	long		match;

	target_node = NULL;
	while (b)
	{
		current_a_node = a;
		match = LONG_MAX;
		while (current_a_node)
		{
			if (current_a_node->value > b->value
				&& current_a_node->value < match)
			{
				match = current_a_node->value;
				target_node = current_a_node;
			}
			current_a_node = current_a_node->next;
		}
		if (match == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	prepare_b_for_push(t_stack **b, t_stack *top_node)
{
	while ((*b) != top_node)
	{
		if (top_node->above_median)
			rb(b, true);
		else
			rrb(b, true);
	}
}
