/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtavares <wtavares@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:47:07 by wtavares          #+#    #+#             */
/*   Updated: 2025/12/18 18:31:40 by wtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// TODO
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
		i++;
	return	(i);
}
char	*ft_strchr(const char *s, int c)
{
	const char *str;
	unsigned char cc;

	str = s;
	cc = (unsigned char) c;
	while (*str)
	{
		if (*str == cc)
			return((char *)str);
		str++;
	}
	if (*str == cc)
		return((char *)str);
	return(NULL);
}
