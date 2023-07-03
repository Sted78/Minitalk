# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 10:42:09 by svanmarc          #+#    #+#              #
#    Updated: 2023/06/26 13:50:14 by svanmarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC		= gcc
CFLAGS		= -Wall -Werror -Wextra -I.

.PHONY: 	all clean fclean re

RM 		= rm -f

SRCS		= ft_atoi.c ft_isdigit.c ft_memmove.c \
			ft_strlen.c ft_toupper.c ft_bzero.c \
			ft_isprint.c ft_memset.c ft_strncmp.c \
			ft_isalnum.c ft_memchr.c ft_strchr.c \
			ft_strnstr.c ft_isalpha.c ft_memcmp.c \
			ft_strlcat.c ft_strrchr.c ft_isascii.c \
			ft_memcpy.c ft_strlcpy.c ft_tolower.c \
			ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			get_next_line.c ft_lstnew.c ft_putnbr_fd.c \
			ft_lstadd_front.c ft_lstsize.c \
                        ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
                        ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			ft_printf.c ft_putchar.c  ft_putstr.c \
			ft_putchar_pf.c ft_putstr_pf.c 

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)
		
$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:		
		$(RM) $(OBJS)
		
fclean:		clean
		$(RM) $(NAME)

re:		fclean all

