ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRCS		= free.c malloc.c realloc.c show_alloc_mem.c \
			  find.c large.c small.c tiny.c \
			  sort_alloc.c aux.c aux_aux.c \
			  ft_atoi.c ft_isalpha.c ft_isdigit.c \
			  ft_isspace.c ft_itoa_base.c ft_printf.c \
			  ft_putchar.c ft_putstr.c ft_putwchar.c \
			  ft_round.c ft_strcmp.c ft_strcpy.c \
			  ft_strdel.c ft_strdup.c ft_strlen.c \
			  ft_strlen_wchar.c ft_strncmp.c \
			  ft_strnew.c ft_strsub.c ft_uitoa_base.c \
			  ptf_booleans.c ptf_controller_a.c \
			  ptf_controller_b.c ptf_controller_cs.c \
			  ptf_controller_di.c ptf_controller_e.c \
			  ptf_controller_f.c ptf_controller_n.c \
			  ptf_controller_o.c ptf_controller_u.c \
			  ptf_controller_xp.c ptf_flag_controller.c \
			  ptf_hour_controller.c ptf_modifier_controller.c \
			  ptf_padding_c.c ptf_padding_e.c ptf_padding_f.c \
			  ptf_padding_ws.c ptf_preci_field_controller.c \
			  ptf_process_conversion.c ptf_process_instruction.c \
			  ptf_put_colors.c

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
	$(CC) -c -o $@ $(CFLAGS) $^ -O0 -g -I $(PATH_INC)/malloc.h

clean:
	@rm -f $(OBJECTS)
	@echo Delete $(words $(OBJECTS)) object file

fclean: clean
	rm -f $(NAME)
	rm -f libft_malloc.so

re: fclean $(NAME)
