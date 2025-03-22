/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:37:17 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/02 16:37:46 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index_median(t_stack *a)
{
	int	i;
	int	stack_size;
	int	median;

	i = 0;
	stack_size = ft_stack_size(a);
	median = stack_size / 2;
	while (a)
	{
		a->index = i;
		if (i <= median)
			a->above_median = true;
		else
			a->above_median = false;
		i++;
		a = a->next;
	}
}

void	find_target_node_for_a(t_stack *a, t_stack *b)
{
	t_stack		*current_b_node;
	t_stack		*target_node;
	long int	best_value;

	target_node = NULL;
	while (a)
	{
		current_b_node = b;
		best_value = LONG_MIN;
		while (current_b_node)
		{
			if (current_b_node->value < a->value
				&& current_b_node->value > best_value)
			{
				best_value = current_b_node->value;
				target_node = current_b_node;
			}
			current_b_node = current_b_node->next;
		}
		if (best_value == LONG_MIN)
			a->target_node = find_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	price_calculation_for_a(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_stack_size(a);
	b_len = ft_stack_size(b);
	while (a)
	{
		a->price = a->index;
		if (!a->above_median)
			a->price = a_len - a->index;
		if (a->target_node->above_median)
			a->price += a->target_node->index;
		else
			a->price += b_len - a->target_node->index;
		a = a->next;
	}
}

void	config_a_cheapest(t_stack *a)
{
	t_stack	*cheapest_node;
	int		cheapest_price;

	cheapest_node = NULL;
	cheapest_price = INT_MAX;
	while (a)
	{
		if (a->price < cheapest_price)
		{
			cheapest_price = a->price;
			cheapest_node = a;
		}
		a->cheapest = false;
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

void	prepare_a_for_push(t_stack **a, t_stack *top_node)
{
	while ((*a) != top_node)
	{
		if (top_node->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}
