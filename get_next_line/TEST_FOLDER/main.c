/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:51:46 by cbach             #+#    #+#             */
/*   Updated: 2020/07/20 19:33:42 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
int main()
{
	int fd = open("test_file.txt", O_RDONLY);
	char **line = malloc(sizeof(char *));
	int rv = get_next_line(fd, line);
	printf("rv = %d\nline = %s\n", rv, *line);

	// char *s = malloc(BUFFER_SIZE + 1);
	// read(fd, s, BUFFER_SIZE);
	// s[BUFFER_SIZE] = '\0';
	// printf("%s", s);
	return (0);
}
