# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akitty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 15:27:51 by akitty            #+#    #+#              #
#    Updated: 2022/02/21 15:27:52 by akitty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_B		=	checker

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

FILES		=	get_data.c \
				commands_1.c commands_2.c commands_3.c \
				utils.c utils_sorting.c \
				general_sorting.c more_sort.c \

SRC_MAIN	=	$(addprefix src/, $(FILES)) \
				src/main.c

BONUS		=	commands_handler.c checker_main.c \

SRC_B		=	$(addprefix src/, $(FILES)) \
				$(addprefix checker_src/, $(BONUS)) \
				

OBJ			=	$(SRC_MAIN:.c=.o)

OBJ_B		=	$(SRC_B:.c=.o)

LIBFT_PATH	=	./libft

LIBFT		=	./libft/libft.a

all:		$(NAME)

bonus:		$(NAME_B)

$(NAME):	$(OBJ)
			$(MAKE) all -C $(LIBFT_PATH)
			$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_B):	$(OBJ_B)
			$(MAKE) all -C $(LIBFT_PATH)
			$(CC) $(FLAGS) $(OBJ_B) $(LIBFT) -o $(NAME_B)

%.o:		%.c
			$(CC) -c $(FLAGS) -o $@ $<

clean:
			$(MAKE) clean -C $(dir $(LIBFT))
			rm -rf $(OBJ) $(OBJ_B)

fclean: 	clean
			$(MAKE) fclean -C $(dir $(LIBFT))
			rm -rf $(NAME) $(NAME_B)

re:			fclean all

.PHONY:		all bonus clean fclean re