#!/usr/bin/make -f
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jelmalem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 16:44:53 by jelmalem          #+#    #+#              #
#    Updated: 2017/01/02 16:45:47 by jelmalem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	lem_in

SRC				=	convert.c			\
					ft_algo.c			\
					parsing.c			\
					ft_managestruct.c	\
					ft_is_number.c		\
					ft_tabchr.c			\
					countstr.c			\
					parsing_second.c	\
					ft_managesline.c	\

OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

CC				=	gcc -g
CFLAGS			=	-Wall -Wextra -Werror

LIBFTPRINTF		=	./libft/libft.a ./libft/libftprintf.a
LIBINC			=	-I./libft/includes
#LIBLINK			=	-L./libft -lft
LIBLINK			=	$(LIBFTPRINTF)
SRC_PATH		=	./src/

INC_PATH		=	./includes/

OBJ_PATH		=	./obj/

all:			libftprintf $(NAME)

$(NAME):	obj $(OBJ)
				@printf "\n=> \x1B[33mCompiling lem_in...\x1b[37m"
				@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
				@printf "\n=> \x1B[32mlem_in done !\x1B[37m\n"

obj:
				@printf "=> \e[38;5;208mMaking lem_in/obj dir... \x1B[37m"
				@mkdir -p $(OBJ_PATH)

libftprintf:	$(LIBFTPRINTF)

$(LIBFTPRINTF):
				make -C ./libft/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@$(CC) $(CFLAGS) $(LIBINC) -I $(INC_PATH) -o $@ -c $<
				@printf "\e[38;5;208m▒\e[0m"

clean:
				@rm -rf $(OBJ_PATH)
				@printf "=> \x1B[31mDeleting lem_in .obj files...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"

fclean:			clean
				@printf "=> \x1B[31mDeleting lem_in...\x1B[37m\n"
				@printf "=> \x1B[31mDeleting libft.a... \x1B[37m\n"
				@rm -rf $(NAME)

re:				fclean all

norme:
				@norminette ./src/
				@norminette ./includes/

.phony : lem_in
