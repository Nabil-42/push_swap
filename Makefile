# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabil <nabil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 14:31:54 by nabil             #+#    #+#              #
#    Updated: 2024/03/11 13:56:00 by nabil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   push_swap
BONUS_NAME	=    checker
CC			=    cc
CFLAGS		=    -Wall -Wextra -Werror -fPIC
RM			=    rm -rf

SRC			= push_swap.c
LIBFT		= Libft/libft.a
BONUS_DIR	= Libft/checker_tools
BONUS		= $(addprefix $(BONUS_DIR)/, basic_check_1.c basic_check_2.c basic_check_3.c checker.c)

OBJ_DIR		=	bin
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS	=	$(addprefix $(OBJ_DIR)/, $(notdir $(BONUS:.c=.o)))

# **************************************************************************** #
# COLORS

GREEN        =    \033[0;32m
GREY        =    \033[1;30m
PURPLE        =    \033[0;93m
BLUE        =    \033[0;94m
CYAN        =    \033[0;36m
END_COLOR    =    \033[0;39m

# **************************************************************************** #
# RULES

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C Libft
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo "$(CYAN)[Executable]$(END_COLOR) $@ is ready !"

$(OBJ): $(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C Libft clean
	@echo "$(CYAN)[All obj]$(END_COLOR) are $@ !"
    
fclean:
	@$(MAKE) -C Libft fclean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(CYAN)[Everything]$(END_COLOR) is fclean !"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	@$(MAKE) -C Libft
	@$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS) $(LIBFT)
	@echo "$(CYAN)[Checker]$(END_COLOR) $@ is ready !"

$(OBJ_BONUS): $(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done."

.PHONY: all clean fclean re bonus
