# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 17:10:59 by ayennoui          #+#    #+#              #
#    Updated: 2020/12/16 16:57:52 by ayennoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIBFT = 	libft/ft_memset.c \
	   			libft/ft_memccpy.c \
	   			libft/ft_memcmp.c \
	   			libft/ft_bzero.c \
	   			libft/ft_memcpy.c \
	   			libft/ft_memmove.c \
	   			libft/ft_memchr.c \
	   			libft/ft_strlen.c \
	   			libft/ft_strlcpy.c \
	   			libft/ft_strlcat.c \
	   			libft/ft_strchr.c \
	   			libft/ft_strnstr.c \
	   			libft/ft_strncmp.c \
	   			libft/ft_atoi.c \
	   			libft/ft_isalpha.c \
	   			libft/ft_isdigit.c \
	   			libft/ft_isalnum.c \
	   			libft/ft_isascii.c \
	   			libft/ft_isprint.c \
	   			libft/ft_toupper.c \
	   			libft/ft_tolower.c \
	   			libft/ft_calloc.c \
	   			libft/ft_strdup.c \
	   			libft/ft_substr.c \
	   			libft/ft_strjoin.c \
	   			libft/ft_strtrim.c \
	   			libft/ft_split.c \
	   			libft/ft_itoa.c \
	   			libft/ft_strmapi.c \
	   			libft/ft_putchar_fd.c \
	   			libft/ft_putstr_fd.c \
	   			libft/ft_putendl_fd.c \
	   			libft/ft_putnbr_fd.c \
	   			libft/ft_strrchr.c \
	   			libft/get_next_line.c \
	   			libft/get_next_line_utils.c 

SRC =			srcs/ft_adv_split.c \
				srcs/ft_cd.c \
				srcs/ft_echo.c \
				srcs/ft_env.c \
				srcs/ft_env_handler.c \
				srcs/ft_env_paths.c \
				srcs/ft_env_pt1.c \
				srcs/ft_error_print.c \
				srcs/ft_execve.c \
				srcs/ft_exit.c \
				srcs/ft_export.c \
				srcs/ft_files.c \
				srcs/ft_init.c \
				srcs/ft_options.c \
				srcs/ft_pipe.c \
				srcs/ft_pwd.c \
				srcs/ft_red.c \
				srcs/ft_rewrite.c \
				srcs/ft_run.c \
				srcs/ft_signals.c \
				srcs/ft_tools_1.c \
				srcs/ft_tools_2.c \
				srcs/ft_tools_3.c \
				srcs/ft_tools_4.c \
				srcs/ft_tools_5.c \
				srcs/ft_tools_6.c \
				srcs/ft_tools_7.c \
				srcs/ft_tools_8.c \
				srcs/ft_tools_9.c \
				srcs/ft_unset.c \
				srcs/ft_exceve_1.c \
				main.c

HEADER =	./libft/libft.h \
			./include/ft_minishell.h \

LIB =		./libft/libft.a \
		
RED		= \033[0;31m
NC		= \033[0m
BLUE	= \033[0;34m
GREAN	= \033[0;32m
YELLOW	= \033[0;33m

FLAGS	= -Wall -Werror -Wextra

COMP	= gcc $(FLAGS)

NAME	= minishell

OBJ = $(SRC:.c=.o)

OBJ_S = $(SRC_LIBFT:.c=.o)

all : $(NAME)

$(NAME)	:	$(OBJ) $(OBJ_S) $(HEADER)
			@make -C libft
			@$(COMP) $(LIB) $(OBJ) -o $(NAME)
			@echo "$(GREAN)Minishell Created$(NC)"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(BLUE)Compiled "$<" successfully!$(NC)"

norm:
	@norminette $(SRC) $(HEADER) $(SRC_LIBFT)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)
	@echo "${RED}Object files been removed${NC}"

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)
	@echo "${RED}Minishell Removed${NC}"

re: fclean all
