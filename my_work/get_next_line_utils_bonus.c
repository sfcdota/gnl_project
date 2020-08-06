/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:02:22 by cbach             #+#    #+#             */
/*   Updated: 2020/07/23 21:17:56 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t n)
{
	unsigned char *s;
	unsigned char *b;

	if (!(s = (unsigned char *)malloc(n)))
		return (NULL);
	b = s;
	while (n--)
		*s++ = '\0';
	return (b);
}

int		str_len(const char *s)
{
	int len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

int		str_line_len(const char *s)
{
	int len;
	int is_found;

	len = 0;
	is_found = 0;
	while (s && *s != '\0' && !is_found)
	{
		if (*s == '\n')
		{
			is_found = 1;
			len--;
		}
		len++;
		s++;
	}
	return (is_found ? -len : len);
}
