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
	int isNewFound;

	isNewFound = 0;
	*left = 0;
	*right = 0;
	while (*c)
	{
		if(!isNewFound)
			*left++;
		else
			*right++;
		if(*c == '\n')
			isNewFound = 1;
		c++;
	}
	return (*right);
	//можно заретёрнить только правое и тогда функцию можно воспринимать как булеву (найден ли символ перехода на новую строку)
}

/*

	А В БУФФЕР ПИШЕТСЯ НУЛЬ ТЕРМИНЕЙТ СИМВОЛ ПРИ READ????

*/

int	read_line(char **line, char *buf, const int fd, char *buffer_remains)
{
	size_t *left;
	size_t *right;
	char *temp;
	int rv;

	rv = 1;
	while(!str_line_len(buf, left, right))
	{
		if (!((temp = ft_bufferjoin(temp, buf))
		&& (buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		&& (rv = read(fd, buf, BUFFER_SIZE) <= 0)))
		{
			free(temp);
			free(buf);
			return (rv == 1? -1 : rv);
		}
	}

	free(left);
	free(right);
	left = NULL;
	right = NULL;
}

int	get_next_line(int fd, char **line)
{
	static char *buffer_remains[FD_MAX_COUNT];
	char *buf;
	int rv;

	if (fd > FD_MAX_COUNT || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
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
		if (rv = read(fd, buf, BUFFER_SIZE) <= 0)
		{
			free(buf);
			buf = NULL;
			return (rv);
		}
	}
	return (read_line(line, buf, fd, buffer_remains[fd]));
}
