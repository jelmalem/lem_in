#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/11 22:25:59 by jelmalem          #+#    #+#              #
#    Updated: 2016/11/10 18:14:53 by jelmalem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a

SRCS		=	ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_strdup.c		\
				ft_strcpy.c		\
				ft_strncpy.c	\
				ft_strcat.c		\
				ft_strncat.c	\
				ft_strlcat.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strstr.c		\
				ft_strnstr.c	\
				ft_strcmp.c		\
				ft_strncmp.c	\
				ft_atoi.c		\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_memalloc.c	\
				ft_memdel.c		\
				ft_strnew.c		\
				ft_strdel.c		\
				ft_strclr.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strmap.c		\
				ft_strmapi.c	\
				ft_strequ.c		\
				ft_strnequ.c	\
				ft_strsub.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_strsplit.c	\
				ft_itoa.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_putendl.c	\
				ft_putnbr.c		\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_lstnew.c		\
				get_next_line.c	\

GCC			=	gcc

SRCS_PATH	=	./

OBJS		=	$(SRCS:.c=.o)

SRCS_FILES	=	$(addprefix $(SRCS_PATH),$(SRCS))

H_PATH		=	./includes/

FLAGS		=	-Werror -Wall -Wextra

all			:	$(NAME)

$(NAME)		:
				$(GCC) -c $(FLAGS) -c $(SRCS_FILES) -I$(H_PATH)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

clean		:
				rm -f $(OBJS)

fclean		:
				rm -f $(OBJS)
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	re clean
