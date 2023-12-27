NAME = push_swap

LIBFT = libft

LIBFTM = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES_1 = push_swap.c

CFILES_2 = 	utils.c \
			sort_func.c \
			sort_small_func.c \
			sort.c \
			instruction_a.c \
			instruction_b.c \
			instruction_c.c \
			quick_sort.c \
			free_error.c \
			get_next_line.c

OBJS_1 = $(CFILES_1:.c=.o)

OBJS_2 = $(CFILES_2:.c=.o)


$(NAME): $(OBJS_1) $(OBJS_2)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) $(LIBFTM) -o $(NAME)
	@echo "\n\033[33mPush_swap is ready ✅\033[0m\n"


all: $(NAME)
	@echo "\n\033[33mAll files compiled successfully ✅\033[0m\n"


clean: pic
		@rm -f $(OBJS_1) $(OBJS_2)
		@make clean -C $(LIBFT)
		@echo "\n\033[33mObjects files deleted ✅\033[0m\n"

fclean: clean
		@make fclean -C $(LIBFT)
		@rm -rf $(NAME)
		@echo "\n\033[33mArchive file deleted ✅\033[0m\n"

re: fclean all

pic :
		@echo "\033[1;33m     .--..--..--..--..--..--.			"