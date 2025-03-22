/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:22:41 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 17:50:14 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *a)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = a;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_stack	*find_cheapest_node(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*cheapest_node;

	tmp = a;
	cheapest_node = NULL;
	while (tmp)
	{
		if (tmp->cheapest)
		{
			cheapest_node = tmp;
			return (cheapest_node);
		}
		tmp = tmp->next;
	}
	return (cheapest_node);
}

bool	check_if_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	if (!tmp)
		return (true);
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else if (tmp->value > tmp->next->value)
			return (false);
	}
	return (true);
}

t_stack	*find_last_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next != NULL)
	{
		a = a->next;
	}
	return (a);
}
