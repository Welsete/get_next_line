/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtavares <wtavares@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:47:03 by wtavares          #+#    #+#             */
/*   Updated: 2025/12/20 22:33:14 by wtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	const char		*str;
	unsigned char	cc;

	str = s;
	cc = (unsigned char) c;
	while (*str)
	{
		if (*str == cc)
			return ((char *)str);
		str++;
	}
	if (*str == cc)
		return ((char *)str);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_joinwash(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*concatenate;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	concatenate = malloc(len1 + len2 + 1);
	if (!concatenate)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(concatenate, s1, len1);
	ft_memcpy(concatenate + len1, s2, len2);
	concatenate[len1 + len2] = '\0';
	free(s1);
	return (concatenate);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}
