/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:10:58 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 18:12:07 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, bool print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		tmp = *a;
		last = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		if (print)
			write(1, "ra\n", 3);
	}
	else
		exit_error("Error\n");
}

void	rb(t_stack **b, bool print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*b && (*b)->next)
	{
		tmp = *b;
		last = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		if (print)
			write(1, "rb\n", 3);
	}
	else
		exit_error("Error\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (print)
		write(1, "rr\n", 3);
}

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while ((*a) != cheapest && *b != cheapest->target_node)
		rr(a, b, true);
	get_index_median(*a);
	get_index_median(*b);
}
