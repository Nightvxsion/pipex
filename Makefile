# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 23:03:35 by marcgar2          #+#    #+#              #
#    Updated: 2025/04/30 17:37:25 by marcgar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f
LIBFT_DIR = ./libft
SRC_DIR = ./srcs
INC = ./inc/pipex.h
BG = \e[1;32m		# BOLD GREEN
PRPL = \e[0;35m 	# PURPLE
NC = \e[0m 			# NO COLOR
BLD_RED = \e[1;31m  # BOLD RED
GOLD = \e[1;93m		# GOLD

LIBFT_SRC = $(LIBFT_DIR)/libft.a

SRCS_OBJ = $(SRC_DIR)/pipex.c \
		   $(SRC_DIR)/utils.c \
		   $(SRC_DIR)/error.c

OBJ = $(SRCS_OBJ:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_SRC)
	@echo "$(BG)---------------------------------------------------------${NC}"
	@echo "$(BG)													  "
	@echo "                 ███████████  █████ ███████████  ██████████ █████ █████"
	@echo "                ░░███░░░░░███░░███ ░░███░░░░░███░░███░░░░░█░░███ ░░███ "
	@echo "                 ░███    ░███ ░███  ░███    ░███ ░███  █ ░  ░░███ ███ "
	@echo "                 ░██████████  ░███  ░██████████  ░██████     ░░█████ "  
	@echo "                 ░███░░░░░░   ░███  ░███░░░░░░   ░███░░█      ███░███ " 
	@echo "                 ░███         ░███  ░███         ░███ ░   █  ███ ░░███ "
	@echo "                 █████        █████ █████        ██████████ █████ █████ "
	@echo "                 ░░░░░        ░░░░░ ░░░░░        ░░░░░░░░░░ ░░░░░ ░░░░░ ${NC}"
	@echo "$(BG)----------------------------------------------------------${NC}"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_SRC) -o $(NAME)

$(LIBFT_SRC):
	@echo "$(PRPL)COMPILING LIBFT...${NC}"
	@make -C $(LIBFT_DIR) -s
	@echo "$(PRPL)COMPILING LIBFT DONE!${NC}"

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT_DIR) -s clean
	@echo "$(BLD_RED)[DELETED OBJ]${NC}"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) -s fclean
	@echo "$(BLD_RED)[DELETED BINARY]${NC}"

re: fclean all

.PHONY: all bonus clean fclean re