# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:44:09 by marcgar2          #+#    #+#              #
#    Updated: 2024/10/09 16:54:21 by marcgar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar -rcs
RM = rm -f
CC = gcc
OBJ = $(SRC:.c=.o)
CCFLAGS = -Wall -Werror -Wextra
NAME = libft.a 
INCLUDE = libft.h
SRC =ft_memset.c\
	ft_bzero.c\
	ft_strlen.c\
	ft_atoi.c\
	ft_isdigit.c\
	ft_isalpha.c\
	ft_isprint.c\
	ft_isascii.c\
	ft_isalnum.c\
	ft_memchr.c\
	ft_memcpy.c\
	ft_memcmp.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strncmp.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_calloc.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putnbr_fd.c\
	ft_putendl_fd.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_itoa.c\
	ft_split.c

BONUSSRC = ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c\

BONUSOBJ = $(BONUSSRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		$(LIB) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOBJ) $(INCLUDE)
		$(LIB) $(NAME) $(BONUSOBJ) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
