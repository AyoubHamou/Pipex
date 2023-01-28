# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 08:31:16 by ahamou            #+#    #+#              #
#    Updated: 2023/01/28 05:42:04 by ahamou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS += -Wall -Werror -Wextra -I Includes

SRCS = main.c Utils/error_message.c Utils/get_path.c Utils/libft_functions.c Sources/child1.c Sources/child2.c\
	Utils/without_exit.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o  $(NAME) $(OBJS)
	
clean :
		rm -rf $(OBJS)

fclean : clean 
		rm -rf $(NAME)

re : fclean all
