/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:03:54 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/13 18:04:24 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**artificial_av;
	char	*args;

	a = NULL;
	b = NULL;
	artificial_av = NULL;
	args = NULL;
	if (ac >= 2 && av_error(&av[1]) == 0)
	{
		args = join_avs(av);
		artificial_av = split_them(args);
		free (args);
		create_stack_a(&a, artificial_av, 2);
		ft_free_split(artificial_av);
	}
	else if (ac > 2)
		create_stack_a(&a, &av[1], 0);
	push_swap_algo(&a, &b);
	ft_clean_stack(&a);
	return (0);
}
