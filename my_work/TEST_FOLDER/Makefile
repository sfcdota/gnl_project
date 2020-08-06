# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbach <cbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 13:44:31 by cbach             #+#    #+#              #
#    Updated: 2020/07/23 20:53:48 by cbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -g3 -Wall -Wextra -Werror -D BUFFER_SIZE=1

all: clear compile run clear

compile:
	@ gcc $(FLAGS) ../get_next_line.c ../get_next_line_utils.c main.c -o f

run:
	@ valgrind --leak-check=yes -v -s ./f
	@ echo
	@ ./f | cat -e

clear:
	@ -rm -f
