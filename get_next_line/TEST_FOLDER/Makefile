# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbach <cbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 13:44:31 by cbach             #+#    #+#              #
#    Updated: 2020/07/10 16:41:44 by cbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=32

all: clear compile run clear

compile:
	@ gcc $(FLAGS) ../*.c main.c -o f

run:
	@ ./f | cat -e

clear:
	@ rm f
	@ rm a.out
