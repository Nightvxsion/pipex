# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 23:03:35 by marcgar2          #+#    #+#              #
#    Updated: 2025/02/14 21:52:25 by marcgar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

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

LIBFT_SRC = $(LIBFT_DIR)/libft.a

SRCS_OBJ = $(SRC_DIR)/pipex.c \
		   $(SRC_DIR)/utils.c

OBJ = $(SRCS_OBJ:.c=.o) $(GNL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_SRC)
	@echo "$(BG)----------------------COMPILING $(NAME)----------------------${NC}"
	@echo "$(BG)													  "
	@echo " ███████████  █████ ███████████  ██████████ █████ █████"
	@echo "░░███░░░░░███░░███ ░░███░░░░░███░░███░░░░░█░░███ ░░███ "
	@echo " ░███    ░███ ░███  ░███    ░███ ░███  █ ░  ░░███ ███ "
	@echo " ░██████████  ░███  ░██████████  ░██████     ░░█████ "  
	@echo " ░███░░░░░░   ░███  ░███░░░░░░   ░███░░█      ███░███ " 
	@echo " ░███         ░███  ░███         ░███ ░   █  ███ ░░███ "
	@echo " █████        █████ █████        ██████████ █████ █████ "
	@echo " ░░░░░        ░░░░░ ░░░░░        ░░░░░░░░░░ ░░░░░ ░░░░░ ${NC}"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_SRC) -o $(NAME)
	@echo "$(BG)[READY TO GO]${NC}"

$(LIBFT_SRC):
	@echo "$(PRPL)----------------------COMPILING LIBFT----------------------${NC}"
	make -C $(LIBFT_DIR) --no-print-directory

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BG)[OK]${NC}"

clean:
	@echo "$(BLD_RED)------------- Cleaning objects -------------${NC}"
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean
	@echo "$(BLD_RED)[DELETED OBJ]${NC}"

fclean: clean
	@echo "$(BLD_RED)------------- Cleaning binary -------------${NC}"
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean
	@echo "$(BLD_RED)[DELETED BINARY]${NC}"

re: fclean all

re_b: fclean bonus

.PHONY: all bonus clean fclean re re_b