NAME	=	push_swap

FLAGS	=	-Wall -Wextra -Werror -g

INCLUDE	=	-Llibft -lft

SRC	=	push_swap.c errors.c parsing.c utils.c utils_extra.c operations.c \
		swap.c rotate.c push.c reverse_rotate.c push_b.c push_a.c

OBJ	=	$(SRC:.c=.o)

LIBFT_P	=	./libft
LIBFT	=	$(LIBFT_P)/libft.a

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	cp libft/libft.a $(NAME)
	cc $(FLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_P)

clean:
	$(MAKE) clean -C $(LIBFT_P)
	rm -f $(NAME)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_P)
	rm -f $(NAME) $(OBJ)

re: fclean all
