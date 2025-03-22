/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:42:43 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 18:15:32 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(t_stack *a, long value)
{
	int	nbr;

	if (a == NULL)
		return (0);
	while (a)
	{
		nbr = (int) value;
		if (nbr == (a)->value)
			return (1);
		a = (a)->next;
	}
	return (0);
}

int	check_valid_input(char *av)
{
	while (*av == 32 || (*av <= 9 && *av >= 13))
		av++;
	if (!(*av == '-' || *av == '+' || (*av >= '0' && *av <= '9')))
		return (1);
	if (*av == '-' || *av == '+')
		if (!(av[1] >= '0' && av[1] <= '9'))
			return (1);
	while (*++av)
	{
		if (!(*av >= '0' && *av <= '9'))
			return (1);
	}
	return (0);
}

int	av_error(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
			j++;
		if (av[i][j] == '\0')
			exit_error("Error\n");
		i++;
	}
	return (0);
}

char	*join_avs(char **av)
{
	int		i;
	char	*line;

	i = 1 ;
	line = NULL;
	if (av[i])
	{
		while (av[i])
		{
			line = ft_strjoin2(line, av[i]);
			line = ft_strjoin2(line, " ");
			i++;
		}
		return (line);
	}
	return (NULL);
}

char	**split_them(char *line)
{
	char	**split_av;

	split_av = NULL;
	if (line)
	{
		split_av = ft_split(line, 32);
		return (split_av);
	}
	else
		return (NULL);
}
