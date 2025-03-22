/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:46:29 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 18:10:49 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, bool print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		last = *a;
		while (last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
		tmp->next = *a;
		*a = tmp;
		if (print)
			write(1, "rra\n", 4);
	}
	else
		exit_error("Error\n");
}

void	rrb(t_stack **b, bool print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*b && (*b)->next)
	{
		last = *b;
		while (last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
		tmp->next = *b;
		*b = tmp;
		if (print)
			write(1, "rrb\n", 4);
	}
	else
		exit_error("Error\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		write(1, "rrr\n", 4);
}

void	ft_rev_rot_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while ((*a) != cheapest && *b != cheapest->target_node)
		rrr(a, b, true);
	get_index_median(*a);
	get_index_median(*b);
}
