/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:16:48 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 18:02:32 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack_a(t_stack **a, char **av, int ac)
{
	long	value;
	int		i;

	value = 0;
	i = 0;
	if (!av)
		return ;
	while (av[i] != NULL)
	{
		if ((check_valid_input(av[i])) == 1)
			err_clean_everything(a, av, ac);
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			err_clean_everything(a, av, ac);
		if (check_for_duplicates(*a, value))
			err_clean_everything(a, av, ac);
		create_stack_append(a, value);
		i++;
	}
}

void	create_stack_append(t_stack **a, long value)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = NULL;
	tmp = NULL;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		free_exit_handel(a, "Error\n");
	new_node->value = (int) value;
	new_node->next = NULL;
	if (!(*a))
	{
		*a = new_node;
		(*a)->prev = NULL;
	}
	else
	{
		tmp = *a;
		if (tmp->next)
			tmp = find_last_node(tmp);
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}

void	push_swap_algo(t_stack **a, t_stack **b)
{
	int	stack_len;

	stack_len = 0;
	if (!(*a))
		return ;
	stack_len = ft_stack_size(*a);
	if (stack_len == 1)
		return ;
	if (!check_if_sorted(*a))
	{
		if (stack_len == 2)
			sa(a, true);
		else if (stack_len == 3)
			sort_three_nodes(a);
		else if (stack_len > 3)
			mechanical_turk(a, b);
	}
}

void	err_clean_everything(t_stack **a, char **av, int ac)
{
	if (*a)
		ft_clean_stack(a);
	if (ac == 2)
		free_av_exit(av, "Error\n");
	exit_error("Error\n");
}
