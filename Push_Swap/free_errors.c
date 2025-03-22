/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:25:33 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 17:48:22 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split[i])
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

int	exit_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}

void	ft_clean_stack(t_stack **a)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!*a)
		return ;
	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

void	free_exit_handel(t_stack **a, char *str)
{
	if (!(*a))
		return ;
	if (*a)
		ft_clean_stack(a);
	exit_error(str);
}

void	free_av_exit(char **av, char *str)
{
	if (av)
		ft_free_split(av);
	exit_error(str);
}
