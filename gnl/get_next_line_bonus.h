/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaako <chaako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:53:16 by chaako            #+#    #+#             */
/*   Updated: 2020/06/05 12:15:43 by chaako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct	s_file
{
	size_t		buf_used_len;
	char		*buf;
	int			fd;
}				t_file;

typedef struct	s_files
{
	size_t		count;
	t_file		*arr;
}				t_files;

int				get_next_line(int fd, char **line);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				resize_mem(void **mem, size_t old_size, size_t new_size);
/*
**  Try to find file with such file descriptor. If unsuccessful - create new
*/
t_file			*get_file(int fd, t_files *file_arr);

#endif
