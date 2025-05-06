# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:46:45 by cscache           #+#    #+#              #
#    Updated: 2025/05/06 14:49:23 by barmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilateur + options
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Nom librairie
NAME = libft.a

# Fichiers sources
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

# Fichiers objets (.c -> .o)
OBJS = $(SRCS:.c=.o)

# Compiler la lib
all: $(NAME)

# Regles de constructiom
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Supp fichiers .o
clean:
	rm -f $(OBJS) $(NAME)

# Supp les .o + la lib
fclean: clean
	rm -f $(NAME)

# Supp et recompile
re: fclean all
	
.PHONY: all clean fclean re
