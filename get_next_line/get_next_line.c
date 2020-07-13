/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:15:52 by cbach             #+#    #+#             */
/*   Updated: 2020/07/10 19:14:28 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char line)

int	get_next_line(int fd, char **line)
{
	static char *fd_arr[FD_MAX_COUNT];
	char *buf;

	if ((fd > FD_MAX_COUNT || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0) &&
	!fd_arr[fd] && !(buf = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	
}
