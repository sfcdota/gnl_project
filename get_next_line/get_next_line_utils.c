/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:02:22 by cbach             #+#    #+#             */
/*   Updated: 2020/07/21 22:02:37 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_len(char *s)
{
	int len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

int		str_line_len(char *s)
{
	int len;

	len = 0;
	while (s && *s != '\n' && *s++)
		len++;
	if (s && *s == '\n')
		return (-len);
	while (s && *s++)
		len++;
	return (len);
}
