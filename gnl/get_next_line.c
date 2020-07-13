/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaako <chaako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:31:07 by chaako            #+#    #+#             */
/*   Updated: 2020/06/06 15:13:45 by chaako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#define LINE_DELIMITER '\n'

static ssize_t	terminate_file(char **line, size_t *line_len)
{
	if (*line_len > 0 && (*line)[*line_len - 1] == LINE_DELIMITER)
		return (1);
	if (!resize_mem((void **)line, \
					*line_len * sizeof(**line), \
					(*line_len + 1) * sizeof(**line)))
		return (-1);
	++(*line_len);
	(*line)[*line_len - 1] = LINE_DELIMITER;
	return (0);
}

static size_t	get_add_count(t_file *file)
{
	size_t	cur_ch_idx;

	cur_ch_idx = 0;
	while (cur_ch_idx < file->buf_used_len)
	{
		if (file->buf[cur_ch_idx] == LINE_DELIMITER)
		{
			++cur_ch_idx;
			break ;
		}
		++cur_ch_idx;
	}
	return (cur_ch_idx);
}

static int		get_next_part(t_file *file, char **line, size_t *line_len)
{
	ssize_t	read_count;
	size_t	add_count;
	size_t	rem_count;

	read_count = 0;
	if (file->buf_used_len == 0)
	{
		read_count = read(file->fd, file->buf, BUFFER_SIZE * sizeof(char));
		file->buf_used_len += read_count;
	}
	if (read_count == -1)
		return (read_count);
	if (file->buf_used_len == 0 && read_count == 0)
		return (terminate_file(line, line_len));
	add_count = get_add_count(file);
	rem_count = file->buf_used_len - add_count;
	if (!resize_mem((void **)line, \
					*line_len * sizeof(**line), \
					(*line_len + add_count) * sizeof(**line)))
		return (-1);
	ft_memmove(*line + *line_len, file->buf, add_count);
	ft_memmove(file->buf, file->buf + add_count, rem_count);
	*line_len += add_count;
	file->buf_used_len = rem_count;
	return (1);
}

static int		read_line(t_file *file, char **line)
{
	size_t	line_len;
	int		read_status;

	line_len = 0;
	read_status = 1;
	while (read_status > 0)
	{
		read_status = get_next_part(file, line, &line_len);
		if (read_status >= 0 && (*line)[line_len - 1] == LINE_DELIMITER)
		{
			(*line)[line_len - 1] = '\0';
			return (read_status);
		}
	}
	if (read_status == -1)
	{
		free(*line);
		*line = NULL;
	}
	if (read_status <= 0)
	{
		free(file->buf);
		file->buf = NULL;
	}
	return (read_status);
}

int				get_next_line(int fd, char **line)
{
	static t_files	files = {0, NULL};
	t_file			*cur_file;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	cur_file = get_file(fd, &files);
	if (cur_file == NULL)
		return (-1);
	if (cur_file->buf == NULL)
		if ((cur_file->buf = malloc(BUFFER_SIZE * sizeof(char))) == NULL)
			return (-1);
	*line = NULL;
	return (read_line(cur_file, line));
}
