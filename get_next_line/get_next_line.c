/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:05:32 by cbach             #+#    #+#             */
/*   Updated: 2020/07/20 20:10:55 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_len(char *s)
{
	int len;

	len = 0;
	while(s && *s != '\n' && *s++)
		len++;
	return (*s == '\n' ? len : -1);
}

int		str_len(char *s)
{
	int len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

void	destroy(void *memory)
{
	if (memory)
		free(memory);
	memory = NULL;
}

char		*bufferjoin(char *s1, char *s2)
{
	char *c;
	char *t;
	char *bs1;
	char *bs2;

	bs1 = s1;
	bs2 = s2;
	c = s1 || s2 ? malloc(str_len(s1) + str_len(s2) + 1) : NULL;
	if (c)
	{
		t = c;
		while (s1 && *s1)
			*t++ = *s1++;
		while (s2 && *s2)
			*t++ = *s2++;
		*t = '\0';
	}
	destroy(bs1);
	destroy(bs2);
	return (c);
}

int			adjust_buf_line(char **temp, char *buf, char *buffer_remains,
int index)
{
	char *old;
	char *bbuf;
	char *beginold;
	char *beginbuffer;
	char *begintemp;

	bbuf = buf;
	old = *temp;
	beginold = old;
	if (!((*temp = malloc(sizeof(char) * (str_len(*temp) + index + 1)))
	&& (buffer_remains = malloc(sizeof(char) * (str_len(&buf[index + 1]) + 1)))
	))
		return (-1);
	begintemp = *temp;
	beginbuffer = buffer_remains;
	while (old && *old)
		*(*temp)++ = *old++;
	while (index--)
		*(*temp)++ = *buf++;
	**temp = '\0';
	while (*(++buf))
		*buffer_remains++ = *buf;
	*buffer_remains = '\0';
	*temp = begintemp;
	buffer_remains = beginbuffer;
	free(beginold);
	free(bbuf);
	return (1);
}


int		read_line(int fd, char **line, char *buf, char *buffer_remains)
{
	int nl_index;
	int rv;

	while (((nl_index = line_len(buf)) == -1))
	{
		if (!((*line = bufferjoin(*line, buf))
		&& (buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		&& ((rv = read(fd, buf, BUFFER_SIZE)) <= 0)))
		{
			printf("line = %p\n", *line);

			printf("buf = %s\n", buf);

			printf("rvvvvv = %d\n", rv);

			destroy(*line);
			destroy(buf);
			return (rv > 1 ? -1 : rv);
		}
	}
	printf("rvvvvv = %d\n", rv);
	rv = adjust_buf_line(line, buf, buffer_remains, nl_index);
	return (rv);
}

int		get_next_line(int fd, char **line)
{
	static char *buffer_remains[FD_MAX_COUNT];
	char		*buf;

	if (fd > FD_MAX_COUNT || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (buffer_remains[fd])
	{
		if (!(buf =bufferjoin(buffer_remains[fd], NULL)))
			return (-1);
	}
	else
	{
		if(!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		read(fd, buf, BUFFER_SIZE);
	}
	return (read_line(fd, line, buf, buffer_remains[fd]));
}
