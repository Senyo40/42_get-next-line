/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragliga <ragliga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:36:37 by ragliga           #+#    #+#             */
/*   Updated: 2026/11/17 11:59:54 by ragliga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_join(int fd, char *rest)
{
	char	*buffer;
	char	*temp_rest;
	int		file_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	file_read = 1;
	while (my_strchr(rest, '\n') == NULL && file_read > 0)
	{
		file_read = read(fd, buffer, BUFFER_SIZE);
		if (file_read < 0)
		{
			free(rest);
			free(buffer);
			return (NULL);
		}
		buffer[file_read] = '\0';
		temp_rest = rest;
		rest = my_strjoin(temp_rest, buffer, file_read);
		free(temp_rest);
	}
	free(buffer);
	return (rest);
}

char	*extract_line(char *rest)
{
	size_t	i;
	char	*line;

	if (!rest)
		return (NULL);
	if (rest[0] == '\0')
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		line = my_substr(rest, 0, i + 1);
	else
		line = my_substr(rest, 0, i);
	return (line);
}

char	*clean_rest(char *rest)
{
	int		i;
	char	*temp_rest;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
	{
		temp_rest = my_substr(rest, i + 1, (my_strlen(rest) - (i + 1)));
		free(rest);
		return (temp_rest);
	}
	else
	{
		free(rest);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*rest[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	rest[fd] = read_join(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = extract_line(rest[fd]);
	rest[fd] = clean_rest(rest[fd]);
	return (line);
}
