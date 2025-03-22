/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:11:34 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/02 17:51:12 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, bool print)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = tmp;
		if (print)
			write(1, "sa\n", 3);
	}
	else
		exit_error("Error\n");
}

void	sb(t_stack **b, bool print)
{
	int	tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = tmp;
		if (print)
			write(1, "sb\n", 3);
	}
	else
		exit_error("Error\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		write(1, "ss\n", 3);
}
