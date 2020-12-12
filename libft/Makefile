# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:28:32 by ayennoui          #+#    #+#              #
#    Updated: 2020/12/11 19:58:25 by ayennoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =  ft_memset.c \
	   ft_memccpy.c \
	   ft_memcmp.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_strlen.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_strchr.c \
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
	   ft_strrchr.c \
	   get_next_line.c \
	   get_next_line_utils.c 

SRCSBON = ft_lstnew_bonus.c \
		  ft_lstadd_front_bonus.c \
		  ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c \
		  ft_lstadd_back_bonus.c \
		  ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c

NAME = libft.a

RED		= \033[0;31m
NC		= \033[0m
BLUE	= \033[0;34m
GREAN	= \033[0;32m
YELLOW	= \033[0;33m

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJSBON = $(SRCSBON:.c=.o)

all: $(NAME)

bonus: $(OBJSBON) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(OBJSBON)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREAN)Libft Created$(NC)"

%.o : %.c
	@gcc -c $(FLAGS) $< -o $@
	@echo "$(BLUE)Compiled "$<" successfully!$(NC)"

clean:
	@rm -f $(OBJ) $(OBJSBON)

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}Libft Removed${NC}"

re: fclean all
