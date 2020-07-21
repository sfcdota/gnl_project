/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:02:35 by cbach             #+#    #+#             */
/*   Updated: 2020/07/21 22:04:09 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_dup(char *s)
{
	char	*t;
	char	*bt;
	int		len;

	if (!(len = str_len(s)))
		return (NULL);
	if (!(t = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	bt = t;
	while (s && *s)
		*t++ = *s++;
	*t = '\0';
	return (bt);
}

int		destroy(void *p1, void *p2, void *p3, int status)
{
	if (p1)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2)
	{
		free(p2);
		p2 = NULL;
	}
	if (p3)
	{
		free(p3);
		p3 = NULL;
	}
	return (status > 0 ? 1 : status);
}


char	*str_join(char *s1, char *s2, int length)
{
	char *out;
	char *begin;
	char *oldbegin;

	if (!(out = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	begin = out;
	oldbegin = s1;
	while (s1 && *s1 && length--)
		*begin++ = *s1++;
	while (s2 && *s2 && length--)
		*begin++ = *s2++;
	*begin = '\0';
	if (oldbegin)
		free(oldbegin);
	return (out);
}

int		read_line(int fd, char **line, char *buf, char **buffer_remains)
{
	int		status;
	char	*temp;
	int		index;

	status = 1;
	temp = NULL;
	while ((index = str_line_len(buf)) > 0 && status != -1)
	{
		if (!(temp = status++ == 1 ? str_dup(buf) :
		str_join(temp, buf, str_len(buf) + str_len(temp))))
			status = -1;
		else
		{
			if (index != BUFFER_SIZE)
			{
				free(buf);
				buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			}
			status = read(fd, buf, BUFFER_SIZE);
		}
	}
	*buffer_remains = status > 0 ? str_dup(&buf[1 - index]) : NULL;
	*line = status > 0 ? str_join(temp, buf, str_len(temp) - index)
	: str_dup("");
	return (destroy(buf, status > 0 ? NULL : *buffer_remains, NULL, status));
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer_remains[FD_MAX_COUNT];
	char		*buf;
	int			status;

	status = 1;
	if (fd > FD_MAX_COUNT || BUFFER_SIZE < 1)
		status = -1;
	if (buffer_remains[fd])
	{
		if (!(buf = str_dup(buffer_remains[fd])))
			status = -1;
		else
		{
			free(buffer_remains[fd]);
			buffer_remains[fd] = NULL;
		}
	}
	else
		status =
		read(fd, buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)), BUFFER_SIZE);
	return (status > 0 ? read_line(fd, line, buf, &buffer_remains[fd])
	: destroy(buf, NULL, NULL, status));
}
