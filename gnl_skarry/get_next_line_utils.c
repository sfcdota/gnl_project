/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:19:07 by skarry            #+#    #+#             */
/*   Updated: 2020/06/06 17:37:17 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strtosup(char const *s, size_t len)
{
	char			*res;
	size_t			i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (!(res = (char *)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

void		*ft_calloc(size_t n, size_t b)
{
	unsigned char	*s;
	unsigned char	*s1;
	int				i;

	if (!(s = (unsigned char*)malloc(n * b)))
		return (NULL);
	i = n * b;
	s1 = s;
	while (i-- > 0)
		*(s++) = 0;
	return (s1);
}

char		*ft_strchr(const char *s, int c)
{
	char	*fin;

	fin = (char *)s;
	while (*fin != c)
	{
		if (!*fin)
			return (NULL);
		fin++;
	}
	return (fin);
}

size_t		ft_strlen(const char *str)
{
	size_t			c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int				len;
	char			*res;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	while (*s1 != '\0')
		*res++ = *s1++;
	while (*s2 != '\0')
		*res++ = *s2++;
	return (res - len);
}
