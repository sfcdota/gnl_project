/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:16:35 by cbach             #+#    #+#             */
/*   Updated: 2020/07/10 19:14:47 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unisth.h>
#include <stdlib.h>
#define FD_MAX_COUNT 1024
#define BUFFER_SIZE 0

int	get_next_line(int fd, char **line);
