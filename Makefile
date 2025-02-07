# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 23:03:35 by marcgar2          #+#    #+#              #
#    Updated: 2025/02/07 10:04:44 by marcgar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT_DIR = ./libft
GNL_DIR = ./gnl
SRC_DIR = ./srcs
INC = ./inc/pipex.h
BG = \e[1;32m		# BOLD GREEN
PRPL = \e[0;35m 	# PURPLE
NC = \e[0m 			# NO COLOR
BLD_RED = \e[1;31m  # BOLD RED
GOLD = \e[1;93m		# GOLD

GNL_SRC = $(GNL_DIR)/get_next_line_bonus.c \
		  $(GNL_DIR)/get_next_line_utils_bonus.c \
		  $(GNL_DIR)/get_next_line_utils.c \
		  $(GNL_DIR)/get_next_line.c

LIBFT_SRC = $(LIBFT_DIR)/ft_bzero.c \
			$(LIBFT_DIR)/ft_atoi.c \
			$(LIBFT_DIR)/ft_itoa.c \
			$(LIBFT_DIR)/ft_calloc.c \
			$(LIBFT_DIR)/ft_memchr.c \
			$(LIBFT_DIR)/ft_memcmp.c \
			$(LIBFT_DIR)/ft_memcpy.c \
			$(LIBFT_DIR)/ft_memmove.c \
			$(LIBFT_DIR)/ft_memset.c \
			$(LIBFT_DIR)/ft_strchr.c \
			$(LIBFT_DIR)/ft_strdup.c \
			$(LIBFT_DIR)/ft_striteri.c \
			$(LIBFT_DIR)/ft_strlcat.c \
			$(LIBFT_DIR)/ft_strlcpy.c \
			$(LIBFT_DIR)/ft_strncmp.c \
			$(LIBFT_DIR)/ft_strnstr.c \
			$(LIBFT_DIR)/ft_strrchr.c \
			$(LIBFT_DIR)/ft_tolower.c \
			$(LIBFT_DIR)/ft_toupper.c \
			$(LIBFT_DIR)/ft_putchar_fd.c \
			$(LIBFT_DIR)/ft_putstr_fd.c \
			$(LIBFT_DIR)/ft_putnbr_fd.c \
			$(LIBFT_DIR)/ft_putendl_fd.c \
			$(LIBFT_DIR)/ft_strjoin.c \
			$(LIBFT_DIR)/ft_strtrim.c \
			$(LIBFT_DIR)/ft_substr.c \
			$(LIBFT_DIR)/ft_strmapi.c \
			$(LIBFT_DIR)/ft_strlen.c \
			$(LIBFT_DIR)/ft_isdigit.c \
			$(LIBFT_DIR)/ft_isalpha.c \
			$(LIBFT_DIR)/ft_isprint.c \
			$(LIBFT_DIR)/ft_isascii.c \
			$(LIBFT_DIR)/ft_isalnum.c

SRCS_BONUS = $(SRC_DIR)/pipex_bonus.c \
		     $(SRC_DIR)/utils_bonus.c \

SRCS_OBJ = $(SRC_DIR)/pipex.c \
		   $(SRC_DIR)/utils.c

TOTAL = $(GNL_SRC) $(LIBFT_SRC) $(SRCS_OBJ)
TOTAL_B = $(SRCS_BONUS)
OBJ = $(TOTAL:.c=.o)
OBJ_B = $(TOTAL_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(BG)[READY TO GO]${NC}"

%.o: %.c
	@echo "$(BG)----------------------COMPILING PIPEX----------------------${NC}"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BG)[OK]${NC}"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_B)
	@echo "$(GOLD)----------------------COMPILING PIPEX_BONUS----------------------${NC}"
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_BONUS)
	@echo "$(GOLD)[READY TO GO]${NC}"

clean:
	@echo "$(BLD_RED)------------- Cleaning objects -------------${NC}"
	$(RM) $(OBJ)
	$(RM) $(OBJ_B)
	@echo "$(BLD_RED)[DELETED OBJ]${NC}"

fclean: clean
	@echo "$(BLD_RED)------------- Cleaning binary -------------${NC}"
	$(RM) $(NAME)
	@echo "$(BLD_RED)[DELETED BINARY]${NC}"

re: fclean all

re_b: fclean bonus

.PHONY: all bonus clean fclean re re_b