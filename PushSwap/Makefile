# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabil <nabil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 14:31:54 by nabil             #+#    #+#              #
#    Updated: 2024/01/09 16:53:55 by nabil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fPIC
RM			=	rm -rf

SRC			= push_swap.c 
LIBFT		= Libft/libft.a

OBJ_DIR		=	bin
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# **************************************************************************** #
# COLORS

GREEN		=	\033[0;32m
GREY		=	\033[1;30m
PURPLE		=	\033[0;93m
BLUE		=	\033[0;94m
CYAN		=	\033[0;36m
END_COLOR	=	\033[0;39m

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
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ)
	@$(MAKE) -C Libft clean
	@echo "$(CYAN)[All obj]$(END_COLOR) are $@ !"
	
fclean:
	@$(MAKE) -C Libft fclean
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ)
	@$(RM) $(NAME) a.out bin
	@echo "$(CYAN)[Everything]$(END_COLOR) is fclean !"

test:
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ)
	@$(RM) $(NAME) a.out bin
	
re: fclean all

.PHONY: all clean fclean re