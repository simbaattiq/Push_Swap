/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:57:40 by mel-atti          #+#    #+#             */
/*   Updated: 2023/11/13 13:08:56 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	**ft_freealoc(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t	ft_wcount(const char *s, char d)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != d)
		{
			count++;
			while (s[i] && s[i] != d)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_word_dup(const char *s, char d)
{
	size_t	len;
	char	*ptr;

	ptr = NULL;
	len = 0;
	while (s[len] && s[len] != d)
		len++;
	ptr = (char *)malloc((len + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	**ft_split(const char *s, char d)
{
	char	**ptr;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	len = ft_wcount(s, d);
	ptr = (char **)malloc((len + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < len)
	{
		while (s[j] == d)
			j++;
		ptr[i] = ft_word_dup(&(s[j]), d);
		if (!ptr[i])
			return (ft_freealoc(ptr));
		while (s[j] != d && s[j])
			j++;
	}
	ptr[i] = NULL;
	return (ptr);
}
