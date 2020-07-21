/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:02:29 by cbach             #+#    #+#             */
/*   Updated: 2020/07/21 22:03:42 by cbach            ###   ########.fr       */
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

int		str_line_len(char *s);
int		str_len(char *s);

#endif
