ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRCS		= free.c malloc.c realloc.c show_alloc_mem.c \
			  find.c large.c small.c tiny.c \
			  sort_alloc.c sort_large.c sort_small.c sort_tiny.c

PATH_OBJ	= obj
PATH_SRC	= src
PATH_INC	= inc

NAME		= libft_malloc_$(HOSTTYPE).so
CFLAGS		= -Wall -Wextra -Werror
DLFLAGS		= -shared -fPIC
OBJECTS		= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))

.PHONY: all

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc $(DLFLAGS) -o $@ $(OBJECTS)
	@rm -f libft_malloc.so
	@ln -s $(NAME) libft_malloc.so
	@echo libft_malloc.so now link to $(NAME)

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	$(CC) -c -o $@ $(CFLAGS) $^  -I $(PATH_INC)/malloc.h

clean:
	@rm -f $(OBJECTS)
	@echo Delete $(words $(OBJECTS)) object file

fclean: clean
	rm -f $(NAME)
	rm -f libft_malloc.so

re: fclean $(NAME)
