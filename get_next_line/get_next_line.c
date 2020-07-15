/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:15:52 by cbach             #+#    #+#             */
/*   Updated: 2020/07/14 21:49:33 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_line_len(char *c, size_t *left, size_t *right)
{
	*left = 0;
	*right = 0;
	while (*c != '\n' && *c++)
		*left++;
	while(*c)
	{
		if(*(++c))
			*right++;
	}
	return (*left + *right);
	//можно заретёрнить только правое и тогда функцию можно воспринимать как булеву (найден ли символ перехода на новую строку)
}

int	split_strjoin(char **begin, char **end, char *str, char c, int length)
{
	free(*begin);
	free(*end);
	if(!(*begin = malloc(sizeof(char) * (length + 1))) ||
	!(*end = malloc(sizeof(char) * (ft_strlen(str) - length + 1))))
		return (-1);





}

int	read_line(char **line, char *buf, char **buffer_remains)
{
	char *end;

	while(true)
	{
		if(end = ft_strchr(buf, '\n'))
		{
			line = ft_strjoin(*line, )
		}
	}
}

int	get_next_line(int fd, char **line)
{
	static char *buffer_remains[FD_MAX_COUNT];
	char *buf;

	if (fd > FD_MAX_COUNT || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (buffer_remains[fd])
	{
		if (!(buf = ft_strdup(buffer_remains[fd])))
			return (-1);
		free(buffer_remains[fd]);
		buffer_remains[fd] = NULL;
	}
	else
	{
		if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		read(fd, buf, BUFFER_SIZE);
	}
	return (read_line(line, buf, buffer_remains));
}
