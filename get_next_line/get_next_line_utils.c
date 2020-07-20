/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:16:38 by cbach             #+#    #+#             */
/*   Updated: 2020/07/19 13:48:14 by cbach            ###   ########.fr       */
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

char		*ft_bufferjoin(char *s1, char *s2)
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

int			adjust_buf_line(char *temp, char *buf, char *buffer_remains,
size_t *linelen, size_t *buflen)
{
	char *old;
	char *bbuf;
	char *beginold;

	bbuf = buf;
	old = temp;
	beginold = old;
	if (!((temp = malloc(sizeof(char) * (ft_strlen(temp) + *linelen + 1)))
	&& (buffer_remains = malloc(sizeof(char) * (*buflen + 1)))))
		return (-1);
	while (*old)
		*temp++ = *old++;
	while ((*linelen)--)
		*temp++ = *buf++;
	*temp = '\0';
	while (*buf)
		*buffer_remains++ = *buf++;
	*buffer_remains = '\0';
	free(linelen);
	free(buflen);
	free(beginold);
	free(bbuf);
	return (1);
}
