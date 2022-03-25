
CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC = ./src/push_swap.c ./src/ft_push.c ./src/instructions.c ./src/instructions_2.c ./src/ft_split.c \
	  ./src/instructions_3.c ./src/push_swap_utils.c ./src/push_swap_utils_2.c ./src/push_swap_utils_3.c ./src/sort_functions.c ./src/ft_substr.c ./src/ft_strdup.c ./src/ft_strlen.c ./src/ft_strlcpy.c
SRC_BONUS =  ./bonus/checker.c ./bonus/checker_utils.c ./bonus/instructions_checker.c ./bonus/instructions_checker_2.c ./bonus/instructions_checker_3.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
			 ./bonus/ft_split.c ./bonus/checker_utils_2.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


bonus: $(NAME_BONUS) $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "Objects Removed !"
fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "Binary Removed !"
re: fclean all

.PHONY: all clean fclean re bonus