/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:07:00 by cbach             #+#    #+#             */
/*   Updated: 2020/07/20 18:46:31 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef FD_MAX_COUNT
#  define FD_MAX_COUNT 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char		*bufferjoin(char *s1, char *s2);
void	*allocate(int size);
int		get_next_line(int fd, char **line);
#endif
