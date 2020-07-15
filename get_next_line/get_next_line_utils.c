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
	while (*s++)
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (n && (dest || src))
	{
		i = 0;
		d = (char *)dest;
		s = (char *)src;
		if (dest < src)
			while (i++ < n)
				*(d++) = *(s++);
		else
			while (i++ < n)
				*(d + n - i) = *(s + n - i);
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	unsigned char *t;

	t = malloc(ft_strlen(s) + 1);
	if (t)
		return (ft_memmove(t, s, ft_strlen(s) + 1));
	return (NULL);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return (*s == c ? (char *)s : NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *c;
	char *t;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	c = s1 && s2 ? malloc(ft_strlen(s1) + ft_strlen(s2) + 1) : NULL;
	if (c)
	{
		t = c;
		while (s1 && *s1)
			*t++ = *s1++;
		while (s2 && *s2)
			*t++ = *s2++;
		*t = '\0';
	}
	return (c);
}
