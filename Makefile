# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cclarke <cclarke@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 13:34:33 by cclarke           #+#    #+#              #
#    Updated: 2026/04/27 13:34:35 by cclarke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

FLAGS	=	-Wall -Wextra -Werror -g

SRC	=	push_swap.c errors.c parsing.c utils.c utils_extra.c operations.c \
		swap.c rotate.c push.c reverse_rotate.c push_b.c push_a.c

OBJ	=	$(SRC:.c=.o)

LIBFT	=	$(LIBFT_P)/libft.a

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	cc $(FLAGS) $(OBJ) -Llibft -lft -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
