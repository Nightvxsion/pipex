# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 23:03:35 by marcgar2          #+#    #+#              #
#    Updated: 2025/02/14 21:26:25 by marcgar2         ###   ########.fr        #
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
		  $(GNL_DIR)/get_next_line_utils_bonus.c 

LIBFT_SRC = $(LIBFT_DIR)/libft.a

SRCS_BONUS = $(SRC_DIR)/pipex_bonus.c \
		     $(SRC_DIR)/utils_bonus.c 

SRCS_OBJ = $(SRC_DIR)/pipex.c \
		   $(SRC_DIR)/utils.c

OBJ = $(SRCS_OBJ:.c=.o) $(GNL_SRC:.c=.o)
OBJ_B = $(SRCS_BONUS:.c=.o) $(GNL_SRC:.c=.o)

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_B) $(LIBFT_SRC)
	@echo "$(GOLD)----------------------COMPILING $(NAME_BONUS)----------------------${NC}"
	@echo -e "$(GOLD)   																"
	@echo -e "		     ██▓███   ██▓ ██▓███  ▓█████ ▒██   ██▒    ██▒   █▓ ██▓ ██▓███  "
	@echo -e "          ▓██░  ██▒▓██▒▓██░  ██▒▓█   ▀ ▒▒ █ █ ▒░   ▓██░   █▒▓██▒▓██░  ██▒ "
	@echo -e "          ▓██░ ██▓▒▒██▒▓██░ ██▓▒▒███   ░░  █   ░    ▓██  █▒░▒██▒▓██░ ██▓▒ "
	@echo -e "          ▒██▄█▓▒ ▒░██░▒██▄█▓▒ ▒▒▓█  ▄  ░ █ █ ▒      ▒██ █░░░██░▒██▄█▓▒ ▒ "
	@echo -e "          ▒██▒ ░  ░░██░▒██▒ ░  ░░▒████▒▒██▒ ▒██▒      ▒▀█░  ░██░▒██▒ ░  ░ "
	@echo -e "          ▒▓▒░ ░  ░░▓  ▒▓▒░ ░  ░░░ ▒░ ░▒▒ ░ ░▓ ░      ░ ▐░  ░▓  ▒▓▒░ ░  ░ "
	@echo -e "          ░▒ ░      ▒ ░░▒ ░      ░ ░  ░░░   ░▒ ░      ░ ░░   ▒ ░░▒ ░      "
	@echo -e "          ░░        ▒ ░░░          ░    ░    ░          ░░   ▒ ░░░        "
	@echo -e "                    ░              ░  ░ ░    ░           ░   ░            "
	@echo -e "                                                        ░                $(NC)" 
	$(CC) $(CFLAGS) $(OBJ_B) $(LIBFT_SRC) -o $(NAME_BONUS)
	@echo "$(GOLD)[READY TO GO]${NC}"

$(LIBFT_SRC):
	@echo "$(PRPL)----------------------COMPILING LIBFT----------------------${NC}"
	make -C $(LIBFT_DIR)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BG)[OK]${NC}"

clean:
	@echo "$(BLD_RED)------------- Cleaning objects -------------${NC}"
	$(RM) $(OBJ) $(OBJ_B)
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