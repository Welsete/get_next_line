/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtavares <wtavares@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:47:07 by wtavares          #+#    #+#             */
/*   Updated: 2025/12/18 18:25:12 by wtavares         ###   ########.fr       */
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
