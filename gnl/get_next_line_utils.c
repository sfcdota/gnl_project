/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaako <chaako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:51:36 by chaako            #+#    #+#             */
/*   Updated: 2020/06/06 13:57:13 by chaako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	cur_byte_idx;
	size_t	bytes_left;
	int		stride;

	bytes_left = n;
	cur_byte_idx = (src > dest ? 0 : n - 1);
	stride = (src > dest ? 1 : -1);
	while (bytes_left > 0)
	{
		((unsigned char *)dest)[cur_byte_idx] = \
			((unsigned char *)src)[cur_byte_idx];
		cur_byte_idx += stride;
		--bytes_left;
	}
	return (dest);
}

int				resize_mem(void **mem, size_t old_size, size_t new_size)
{
	size_t	bytes_to_cpy;
	void	*newmem;

	newmem = malloc(new_size);
	if (newmem != NULL)
	{
		bytes_to_cpy = old_size < new_size ? old_size : new_size;
		ft_memmove(newmem, *mem, bytes_to_cpy);
		free(*mem);
		*mem = newmem;
		return (1);
	}
	return (0);
}

static t_file	*add_new_file(int fd, t_files *files)
{
	size_t	new_file_idx;

	if (!resize_mem((void **)(&files->arr), \
					sizeof(*files->arr) * files->count, \
					sizeof(*files->arr) * (files->count + 1)))
		return (NULL);
	new_file_idx = files->count;
	files->arr[new_file_idx].buf_used_len = 0;
	files->arr[new_file_idx].buf = NULL;
	files->arr[new_file_idx].fd = fd;
	++files->count;
	return (&files->arr[new_file_idx]);
}

t_file			*get_file(int fd, t_files *files)
{
	size_t	cur_file_idx;

	cur_file_idx = 0;
	while (cur_file_idx < files->count)
	{
		if (files->arr[cur_file_idx].fd == fd)
			return (&files->arr[cur_file_idx]);
		++cur_file_idx;
	}
	return (add_new_file(fd, files));
}
