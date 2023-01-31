# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 08:31:16 by ahamou            #+#    #+#              #
#    Updated: 2023/01/31 03:58:50 by ahamou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS = pipex_bonus

CC = cc

CFLAGS += -Wall -Werror -Wextra -I Includes

LIBFT  = libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strrchr.c\
	libft/ft_substr.c libft/ft_split.c libft/ft_strjoin.c\
	libft/ft_memset.c libft/ft_calloc.c libft/ft_strdup.c\

SRCS = Sources/main.c Sources/child1.c Sources/child2.c Utils/error_message.c Utils/get_path.c  Utils/without_exit.c

OBJS = $(SRCS:.c=.o) $(LIBFT:.c=.o)

B_SRCS = bonus/main_bonus.c bonus/heredoc_bonus.c bonus/lastchild_multi_bonus.c bonus/otherchild_multi_bonus.c\
	bonus/heredoc_utils_bonus.c bonus/child1_here_bonus.c bonus/child2_here_bonus.c\
	Utils/error_message.c Utils/get_path.c Utils/without_exit.c\
	bonus/pipex.c\

B_OBJS = $(B_SRCS:.c=.o) $(LIBFT:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  

bonus : $(BONUS)

$(BONUS) : $(B_OBJS)
		@$(CC) $(CFLAGS) $(B_OBJS) -o $(BONUS)

clean :
		@rm -rf $(OBJS) $(B_OBJS)

fclean : clean 
		@rm -rf $(NAME) $(BONUS)

re : fclean all
