# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/02 03:26:29 by adebray           #+#    #+#              #
#    Updated: 2015/04/02 18:39:57 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
HEADDIR			=	inc
HEADFLAG		=	-I ./$(HEADDIR)

SRCDIR			=	src
SRC				=
OBJ				=	$(subst .c,.o,$(SRC))

CC				=	clang
CCFLAGS			=	-Werror -Wall -Wextra -Wuninitialized -O3

LIBLIBFT		=	-L$(SRCDIR)/libft -lft
LIBPRINTF		=	-L$(SRCDIR)/ft_printf -lftprintf
LIBESSENTIAL	=	$(LIBLIBFT) $(LIBPRINTF)

# LIBNCURSES		=	-lncurses

LIBPUSHSWAP		=	$(LIBESSENTIAL) -L$(SRCDIR)/push_swap -lpush_swap

.PHONY: all clean fclean re $(NAME) asm

all: $(NAME)

makelib: _libft _printf _push_swap

test: makelib test.o
	@$(CC) $(CCFLAGS) -g3 $(HEADFLAG) $(LIBPUSHSWAP) -o test $(OBJ) test.c stack.c tree.c
	@echo '!'
	@echo "\033[32m•\033[0m test compil: \033[32m$(NAME)\033[0m"

$(NAME): makelib $(OBJ)
	@$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBPUSHSWAP) -o $(NAME) $(OBJ) main.c
	@echo '!'
	@echo "\033[32m•\033[0m $(NAME) compil: \033[32m$(NAME)\033[0m"

_libft: $(HEADDIR)/libft.h
	@make -C $(SRCDIR)/libft

_printf: $(HEADDIR)/ft_printf.h
	@make -C $(SRCDIR)/ft_printf

_push_swap: $(HEADDIR)/push_swap.h
	@make -C $(SRCDIR)/push_swap

%.o: %.c
	@echo '.''\c'
	@$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	@make -C $(SRCDIR)/libft clean
	@make -C $(SRCDIR)/ft_printf clean
	@make -C $(SRCDIR)/push_swap clean
	@rm -f $(OBJ)
	@echo "\033[31m•\033[0m $(NAME) clean.\033[0m"

fclean:
	@make -C $(SRCDIR)/libft fclean
	@make -C $(SRCDIR)/ft_printf fclean
	@make -C $(SRCDIR)/push_swap fclean
	@rm -f $(OBJ)
	@rm -f $(LIBNAME)
	@rm -f $(NAME)
	@rm -f asm
	@echo "\033[31m•\033[0m $(NAME) fclean: \033[31m$(NAME)\033[0m"

re: fclean all
