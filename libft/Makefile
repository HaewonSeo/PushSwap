# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haseo <haseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 16:49:36 by haseo             #+#    #+#              #
#    Updated: 2021/10/02 16:47:48 by haseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

# ----------------------------------
# Compile flag
# ----------------------------------
CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
ARFLAGS			= rcs
# CFLAGS			+= -g3 -fsanitize=address
# CFLAGS			+= -g

# ----------------------------------
# Command
# ----------------------------------

RM				= rm -rf
MKDIR			= mkdir -p
RMDIR			= rmdir
ECHO			= echo
AR				= ar


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


SRCS =		ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoabase.c \
			get_next_line.c \
			ft_putstr.c \
			ft_exit.c \
			ft_isformat.c \
			ft_free2d.c \
			ft_isdigit_str.c \
			ft_cntword.c \
			ft_strcmp.c

B_SRCS =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstmaxwidth.c

# ----------------------------------
# Directory
# ----------------------------------

LIBFT_DIR		= .
INC_DIR			= .
SRC_DIR			= .
OBJ_DIR			= ./obj

OBJS		= $(addprefix $(OBJ_DIR)/, ${SRCS:.c=.o})
B_OBJS		= $(addprefix $(OBJ_DIR)/, ${B_SRCS:.c=.o})

# ----------------------------------
# Rules
# ----------------------------------

all:		$(OBJ_DIR) ${OBJS} ${NAME}

bonus:		all $(B_OBJS)
			@${AR} ${ARFLAGS} ${NAME} $(B_OBJS)

$(OBJ_DIR):
			@$(MKDIR) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@${CC} -c ${CFLAGS} -o $@ $< -I${INC_DIR}

$(NAME):	${OBJS}
			@${AR} ${ARFLAGS} $@ $^
			@$(ECHO) "$(GREEN)[Success]\t $(BLUE)Create $@ \t$(NOCOLOR)"

clean:
			@${RM} ${OBJS} ${B_OBJS}
			@$(RM) $(OBJ_DIR)

fclean:		clean
			@${RM} ${NAME}

re:			fclean all


.PHONY: 	all clean fclean re bonus
