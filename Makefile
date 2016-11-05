NAME = malloc
SRC_NAME = main.c
OBJ_NAME = $(SRC_NAME:.c=.o)
	OBJ_PATH = obj/
	SRC_PATH = src/
	SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
	OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
	SRCI = includes/libft.h includes/malloc.h
	FLAG = -Wall -Wextra -Werror
	LIB = libft/libft.a

$(NAME) : $(OBJ)
	make -C ./libft
	gcc $(FLAG) $^ $(LIB) -o $@

all : $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAG) -o $@ -c $<

clean :
	rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft

re : fclean all

norme:
	norminette */*.[ch]

.PHONY : all clean fclean re norme
