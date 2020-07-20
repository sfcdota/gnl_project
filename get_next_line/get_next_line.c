/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:15:52 by cbach             #+#    #+#             */
/*   Updated: 2020/07/19 14:12:17 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_line_len(char *c, size_t *left, size_t *right)
{
	*left = 0;
	*right = 0;
	while (*c != '\n' && *c++)
		(*left)++;
	if (*c == '\n')
		c++;
	while (*c++)
		(*right)++;
	return (*right);
}

int		read_line(char **line, char *buf, const int fd, char *buffer_remains)
{
	size_t	*left;
	size_t	*right;
	char	*temp;
	int		rv;

	rv = 1;
	while (!str_line_len(buf, *&left, *&right))
	{
		if (!((temp = ft_bufferjoin(temp, buf))
		&& (buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		&& (rv = read(fd, buf, BUFFER_SIZE) <= 0)))
		{
			free(temp);
			free(buf);
			return (rv > 1 ? -1 : rv);
		}
	}
	rv = adjust_buf_line(temp, buf, buffer_remains, left, right);
	*line = temp;
	return (rv);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer_remains[FD_MAX_COUNT];
	char		*buf;
	int			rv;

	if (fd > FD_MAX_COUNT || !line || BUFFER_SIZE <= 0 || read(fd, buffer_remains[fd], 0) < 0)
		return (-1);
	if (buffer_remains[fd])
	{
		if (!(buf = ft_bufferjoin(buffer_remains[fd], NULL)))
			return (-1);
	}
	else
	{
		if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		if ((rv = read(fd, buf, BUFFER_SIZE) <= 0))
		{
			free(buf);
			buf = NULL;
			return (rv);
		}
		buf[BUFFER_SIZE] = '\0';
	}
	return (read_line(line, buf, fd, buffer_remains[fd]));
}
