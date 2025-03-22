/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:49:06 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 18:14:15 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, bool print)
{
	t_stack	*tmp;

	if (!*b)
		exit_error("Error\n");
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		(*a)->next = NULL;
	}
	else if (*a)
	{
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		tmp->next = *a;
		(*a)->prev = tmp;
		*a = tmp;
	}
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	t_stack	*tmp;

	if (!*a)
		exit_error("Error\n");
	else if (!*b)
	{
		*b = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		(*b)->next = NULL;
	}
	else if (*b)
	{
		tmp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		tmp->next = *b;
		(*b)->prev = tmp;
		*b = tmp;
	}
	if (print)
		write(1, "pb\n", 3);
}
