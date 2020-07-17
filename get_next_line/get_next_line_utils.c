/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:16:38 by cbach             #+#    #+#             */
/*   Updated: 2020/07/14 20:58:22 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && *s++)
		i++;
	return (i);
}

char	*ft_copybuf(const char *s)
{
	unsigned char *t;
	size_t len;

	len = ft_strlen(s) + 1;
	if (!(t = malloc(len)))
		return (NULL);
	return (ft_memmove(t, s, len));
}

char	*ft_bufferjoin(char *s1, char *s2)
{
	char *c;
	char *t;
	char *bs1;
	char *bs2;

	bs1 = s1;
	bs2 = s2;
	c = s1 || s2 ? malloc(ft_strlen(s1) + ft_strlen(s2) + 1) : NULL;
	if (c)
	{
		t = c;
		while (s1 && *s1)
			*t++ = *s1++;
		while (s2 && *s2)
			*t++ = *s2++;
		*t = '\0';
	}
	free(bs1);
	free(bs2);
	bs1 = NULL;
	bs2 = NULL;
	return (c);
}

int		asdfasdf(char *dst, char *src, size_t dst_size, size_t start, size_t count)
{
	char *begin_src;

	if(!(dst = malloc(sizeof(char) * (dst_size + 1))))
		return (-1);
	begin_src = src;
	while(count--)
	{
		*dst++ = *(src + start);
		src++;
	}
	*dst = '\0';
	free(begin_src);
	begin_src = NULL;
}

int		adjust_buf_line(char *temp, char *buf, char *buffer_remains, size_t linelen, size_t buflen)
{
	char *old;
	char *bbuf;
	char *beginold;
	char *bbr;

	bbuf = buf;
	old = temp;
	beginold = old;
	if (!(temp = malloc(sizeof(char) * (ft_strlen(temp)) + linelen)
	&& (buffer_remains = malloc(sizeof(char) * (buflen + 1)))))
		return (-1);
	bbr = buffer_remains;
	while(*old)
		*temp++ = *old++;
	while(linelen--)
		*temp++ = *buf++;
	*temp = '\0';
	free(beginold);
	buffer_remains
}
