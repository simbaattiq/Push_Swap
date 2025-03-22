/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:51:11 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/15 15:39:35 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (ac < 2)
		return (1);
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
	ft_checker(&a, &b);
	ft_clean_stack(&a);
	return (0);
}

void	ft_checker(t_stack **a, t_stack **b)
{
	int		stack_len;
	char	*line;

	stack_len = ft_stack_size(*a);
	line = get_next_line(0);
	while (line)
	{
		handel_commands(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_if_sorted(*a) && ft_stack_size(*a) == stack_len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	handel_commands(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, false);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, false);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, false);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, false);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b, false);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, false);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, false);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, false);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, false);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, false);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, false);
	else
		mf_free_error(a, b, line, "Error\n");
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (i < n && (ss1[i] != '\0' && ss2[i] != '\0') && (ss1[i] == ss2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return (ss1[i] - ss2[i]);
}

void	mf_free_error(t_stack **a, t_stack **b, char *line, char *str)
{
	if (line)
		free (line);
	if (*a)
		ft_clean_stack(a);
	if (*b)
		ft_clean_stack(b);
	exit_error(str);
}
