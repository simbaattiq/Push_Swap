/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:21:06 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/02 19:12:23 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mechanical_turk(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = ft_stack_size(*a);
	if (a_size-- > 3 && !check_if_sorted(*a))
		pb(a, b, true);
	if (a_size-- > 3 && !check_if_sorted(*a))
		pb(a, b, true);
	while (a_size > 3 && !check_if_sorted(*a))
	{
		initialize_a_nodes(*a, *b);
		move_nodes_to_b(a, b);
		a_size--;
	}
	sort_three_nodes(a);
	while (*b)
	{
		initialize_b_nodes(*a, *b);
		move_nodes_to_a(a, b);
	}
	get_index_median(*a);
	min_to_top(a);
}

void	initialize_a_nodes(t_stack *a, t_stack *b)
{
	get_index_median(a);
	get_index_median(b);
	find_target_node_for_a(a, b);
	price_calculation_for_a(a, b);
	config_a_cheapest(a);
}

void	move_nodes_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest_node(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		ft_rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		ft_rev_rot_both(a, b, cheapest);
	prepare_a_for_push(a, cheapest);
	prepare_b_for_push(b, cheapest->target_node);
	pb(a, b, true);
}

void	initialize_b_nodes(t_stack *a, t_stack *b)
{
	get_index_median(a);
	get_index_median(b);
	find_target_node_for_b(a, b);
}

void	move_nodes_to_a(t_stack **a, t_stack **b)
{
	prepare_a_for_push(a, (*b)->target_node);
	pa(a, b, true);
}
