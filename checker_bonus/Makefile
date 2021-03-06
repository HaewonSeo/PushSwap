# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haseo <haseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 00:09:02 by haseo             #+#    #+#              #
#    Updated: 2021/10/02 16:41:24 by haseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= checker

# ----------------------------------
# Compile flag
# ----------------------------------
CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
# CFLAGS			+= -g3 -fsanitize=address
# CFLAGS			+= -g

# ----------------------------------
# Command
# ----------------------------------

MV				= move
RM				= rm -f
MKDIR			= mkdir -p
RMDIR			= rm -rf
ECHO			= echo

# ----------------------------------
# Echo Color
# ----------------------------------

NOCOLOR			= \033[0m
RED				= \033[0;31m
GREEN			= \033[0;32m
ORANGE			= \033[0;33m
BLUE			= \033[0;34m
PURPLE			= \033[0;35m
CYAN			= \033[0;36m
LIGHTGRAY		= \033[0;37m
DARKGRAY		= \033[1;30m
LIGHTRED		= \033[1;31m
LIGHTGREEN		= \033[1;32m
YELLOW			= \033[1;33m
LIGHTBLUE		= \033[1;34m
LIGHTPURPLE		= \033[1;35m
LIGHTCYAN		= \033[1;36m
WHITE			= \033[1;37m

# ----------------------------------
# Source & Object file
# ----------------------------------

SRCS_LIST		=	checker.c \
					push_argv.c \
					valid.c \
					push.c \
					swap.c \
					rotate.c \
					reverse_rotate.c


SRCS			= $(addprefix $(SRC_DIR)/, $(SRCS_LIST))
OBJS			= $(addprefix $(OBJ_DIR)/, $(SRCS_LIST:.c=.o))

# ----------------------------------
# Directory
# ----------------------------------

LIBFT_DIR		=	../libft
CUR_DIR			=	checker_bonus
INC_DIR			=	./inc
SRC_DIR			=	./src
OBJ_DIR			=	./obj
VPATH_DIR		=	./src \
					./src/validation \
					./src/operation

vpath %.c $(VPATH_DIR)

# ----------------------------------
# Library
# ----------------------------------

LIBFT			= libft.a
LIB				= -lft

# ----------------------------------
# Rules
# ----------------------------------

all:			$(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
					@$(MKDIR) $@
					@$(ECHO) "$(GREEN)[Success]\t $(ORANGE)Create $(CUR_DIR)/obj$(NOCOLOR)"

$(OBJ_DIR)/%.o: %.c
					@$(CC) -c $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -o $@ $^
					@$(ECHO) "$(GREEN)[Success]\t $(ORANGE)Create $(CUR_DIR)/$@$(NOCOLOR)"

$(LIBFT):
					@$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME):		$(OBJS)
					@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -o $@ $^ $(LIB)
					@$(ECHO) "$(GREEN)[Success]\t $(BLUE)Create $@$(NOCOLOR)"

clean:
					@$(MAKE) -C $(LIBFT_DIR) clean
					@$(RM) $(OBJS)
					@$(RMDIR) $(OBJ_DIR)
					@$(ECHO) "$(GREEN)[Success]\t $(RED)Remove $(NAME)/$(OBJ_DIR)$(NOCOLOR)"

fclean:			clean
					@$(MAKE) -C $(LIBFT_DIR) fclean
					@$(RM) $(NAME)
					@$(ECHO) "$(GREEN)[Success]\t $(RED)Remove $(NAME)$(NOCOLOR)"

re:				fclean all

.PHONY: 		all clean fclean re
