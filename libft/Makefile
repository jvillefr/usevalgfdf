# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvillefr <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 14:24:05 by jvillefr          #+#    #+#              #
#    Updated: 2021/06/06 14:25:32 by jvillefr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= libft.a
SRCS 	= ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c\
		ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memchr.c\
		ft_memmove.c ft_putendl_fd.c ft_split.c ft_strjoin.c ft_strlen.c\
		ft_strnstr.c ft_substr.c ft_atoi.c ft_calloc.c ft_isascii.c ft_itoa.c\
		ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strlcat.c\
		ft_strmapi.c ft_strrchr.c ft_tolower.c ft_atoi_l.c ft_tab_size.c\
		ft_realloc.c ft_putstr.c
OBJS 	= ${SRCS:.c=.o}

HEADER	= libft.h

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c libft.h
					${CC} ${CFLAGS} -I ${HEADER} -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					ar rc ${NAME} ${OBJS}

all: 		${NAME}

clean:
					rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus%
