/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:30:17 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/27 16:30:24 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result * sign);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (dsize == 0)
		return (i);
	while (src[j] && j < (dsize - 1))
	{
		dst[j] = src[j];
		j++;
	}
	if (j < dsize)
		dst[j] = '\0';
	return (i);
}

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *) malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	result = ft_str_append(s1, s2, result);
	free (s1);
	return (result);
}

char	*ft_str_append(char *s1, char *s2, char *result)
{
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1)
	{
		while (s1[len1] != '\0')
		{
			result[len1] = s1[len1];
			len1++;
		}
	}
	while (s2[len2] != '\0')
		result[len1++] = s2[len2++];
	result[len1] = '\0';
	return (result);
}
