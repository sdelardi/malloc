ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

SRC_NAME = malloc.c large.c tiny.c small.c free.c realloc.c find.c \
		   sort_tiny.c sort_small.c sort_large.c sort_alloc.c
OBJ_NAME = $(SRC_NAME:.c=.o)
	OBJ_PATH = obj/
	SRC_PATH = src/
	SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
	OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
	SRCI = libft/libft.h includes/malloc.h
	FLAG = -Wall -Wextra -Werror
	LIB = libft/libft.a

$(NAME) : $(OBJ)
	make -C ./libft
	gcc $(FLAG) $^ $(LIB) -shared -o $@
	rm -f libft_malloc.so
	ln -s $(NAME) libft_malloc.so

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
	rm -f libft_malloc.so
	make fclean -C ./libft

re : fclean all

norme:
	norminette */*.[ch]

.PHONY : all clean fclean re norme
