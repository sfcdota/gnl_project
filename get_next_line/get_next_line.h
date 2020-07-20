/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:16:35 by cbach             #+#    #+#             */
/*   Updated: 2020/07/19 14:13:35 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define FD_MAX_COUNT 1024
# define BUFFER_SIZE 0

size_t		str_line_len(char *c, size_t *left, size_t *right);
int			read_line(char **line, char *buf, const int fd,
char *buffer_remains);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_bufferjoin(char *s1, char *s2);
int			adjust_buf_line(char *temp, char *buf, char *buffer_remains,
size_t *linelen, size_t *buflen);

#endif
