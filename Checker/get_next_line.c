/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:10:55 by mel-atti          #+#    #+#             */
/*   Updated: 2023/12/19 15:11:08 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	static char	*line_buff;
	char		*rtn_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line_buff = ft_line_scooper(line_buff, fd);
	if (!line_buff)
		return (NULL);
	rtn_line = ft_line_getter(line_buff);
	line_buff = ft_line_cleaner(line_buff);
	if (*line_buff == '\0')
		free(line_buff);
	return (rtn_line);
}
