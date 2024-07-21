/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:39:12 by parden            #+#    #+#             */
/*   Updated: 2024/06/11 18:15:51 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	unload_buffer(char *line, char *buf)
{
	size_t	i;
	size_t	end;

	end = 0;
	i = 0;
	while (end < BUFFER_SIZE && buf[end] && (!end || buf[end - 1] != '\n'))
		end++;
	while (i < BUFFER_SIZE)
	{
		if (i < end)
			line[i] = buf[i];
		if (i + end < BUFFER_SIZE)
			buf[i] = buf[i + end];
		else
			buf[i] = 0;
		i++;
	}
	return (end);
}

void	my_realloc(char **line, size_t *size_line, size_t len_line)
{
	char	*res;

	if (!*size_line)
	{
		*line = malloc(BUFFER_SIZE + 1);
		*size_line = BUFFER_SIZE + 1;
		return ;
	}
	res = malloc(*size_line * 2);
	if (!res)
	{
		free(*line);
		*line = NULL;
		return ;
	}
	ft_memcpy(res, *line, len_line);
	free(*line);
	*size_line *= 2;
	*line = res;
}

char	*populate_line(size_t *len_line, char *buffer, int fd)
{
	char		*line;
	size_t		size_line;
	int			bytes_read;

	size_line = 0;
	while (1)
	{
		if (*len_line + 1 + BUFFER_SIZE > size_line)
			my_realloc(&line, &size_line, *len_line);
		if (!line)
			return (NULL);
		*len_line += unload_buffer(line + *len_line, buffer);
		if (*len_line && line[*len_line - 1] == '\n')
			return (line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
			return (line);
		if (bytes_read == -1)
		{
			ft_memset(buffer, 0, BUFFER_SIZE);
			free(line);
			return (NULL);
		}
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*res;
	size_t		len_line;
	static char	stash[FD_MAX][BUFFER_SIZE];

	if (fd < 0 || fd >= FD_MAX)
		return (NULL);
	len_line = 0;
	line = populate_line(&len_line, stash[fd], fd);
	if (!line || !len_line)
		return (free(line), NULL);
	line[len_line] = 0;
	res = ft_strdup(line);
	free(line);
	return (res);
}
