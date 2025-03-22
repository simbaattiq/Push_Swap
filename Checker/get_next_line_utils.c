/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:18:02 by mel-atti          #+#    #+#             */
/*   Updated: 2023/12/14 14:54:08 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_str_search(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_line_scooper(char *line_buff, int fd)
{
	char	*read_buff;
	ssize_t	br;

	read_buff = NULL;
	br = 1;
	read_buff = (char *) malloc(BUFFER_SIZE + 1);
	if (!read_buff)
		return (NULL);
	while (fd >= 0 && br != 0 && ft_str_search(line_buff, '\n') == NULL)
	{
		br = read(fd, read_buff, BUFFER_SIZE);
		if (br == -1)
		{
			free (read_buff);
			return (NULL);
		}
		read_buff[br] = '\0';
		line_buff = ft_strjoin2(line_buff, read_buff);
	}
	free(read_buff);
	return (line_buff);
}

char	*ft_line_getter(char *line_buff)
{
	char	*cup_str;
	int		len;

	len = 0;
	if (!line_buff[len])
		return (NULL);
	while (line_buff[len] != '\n' && line_buff[len] != '\0')
		len++;
	cup_str = (char *) malloc (len + 2);
	if (!cup_str)
		return (NULL);
	len = 0;
	while (line_buff[len] != '\n' && line_buff[len] != '\0')
	{
		cup_str[len] = line_buff[len];
		len++;
	}
	if (line_buff[len] == '\n')
	{
		cup_str[len] = '\n';
		len++;
	}
	cup_str[len] = '\0';
	return (cup_str);
}

char	*ft_line_cleaner(char *line_buff)
{
	char	*cup_str2;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (line_buff[len] != '\n' && line_buff[len] != '\0')
		len++;
	if (!line_buff[len])
	{
		free (line_buff);
		return (NULL);
	}
	cup_str2 = (char *) malloc (ft_strlen(line_buff) - len);
	if (!cup_str2)
		return (NULL);
	len++;
	while (line_buff[len] != '\0')
		cup_str2[i++] = line_buff[len++];
	cup_str2[i] = '\0';
	free (line_buff);
	return (cup_str2);
}
