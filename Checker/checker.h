/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:51:41 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/27 17:27:00 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Push_Swap/push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

void	ft_checker(t_stack **a, t_stack **b);
void	handel_commands(t_stack **a, t_stack **b, char *line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/************* get next line ***************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_line_scooper(char *line_buff, int fd);
char	*ft_line_getter(char *line_buff);
char	*ft_line_cleaner(char *line_buff);
char	*ft_str_search(char *str, int c);
void	mf_free_error(t_stack **a, t_stack **b, char *line, char *str);

#endif
