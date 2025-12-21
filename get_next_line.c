/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtavares <wtavares@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:47:07 by wtavares          #+#    #+#             */
/*   Updated: 2025/12/20 22:33:42 by wtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_and_stash(fd, &stash) == -1)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (extract_line(&stash));
}

int	read_and_stash(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes = 1;
	while (bytes > 0 && (!*stash || !ft_strchr(*stash, '\n')))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[bytes] = '\0';
		if (bytes > 0)
			*stash = ft_joinwash(*stash, buffer);
	}
	free(buffer);
	return (0);
}

char	*extract_line(char **stash)
{
	char	*newline_ptr;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	newline_ptr = ft_strchr(*stash, '\n');
	if (!newline_ptr)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	line = create_line(*stash, newline_ptr);
	update_stash(stash, newline_ptr);
	return (line);
}

void	update_stash(char **stash, char *newline_ptr)
{
	char	*new_stash;

	if (*(newline_ptr + 1))
	{
		new_stash = ft_strdup(newline_ptr + 1);
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
}

char	*create_line(char *stash, char *newline_ptr)
{
	char	*line;
	size_t	len;

	len = (newline_ptr - stash) + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, len);
	line[len] = '\0';
	return (line);
}
