/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:51:46 by cbach             #+#    #+#             */
/*   Updated: 2020/07/22 13:10:17 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
int main()
{
	int fd = open("test_file.txt", O_RDONLY);
	char **line = malloc(BUFFER_SIZE + 1);
	int status;
	while ((status = get_next_line(fd, line)) > 0)
	{
		printf("line = %s\t\t status = %d\n", *line, status);
	}
		//printf("line = %s\n", *line);
	// char *s = malloc(BUFFER_SIZE + 1);
	//int a = read(fd, NULL, BUFFER_SIZE);
	// s[BUFFER_SIZE] = '\0';
	//printf("%d", a);
	return (0);
}
