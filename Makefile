# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
AR      = ar -crs
RM      = rm -f

# Program name
NAME    = libftprintf.a

# External library
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source and object files
SRCS    = ft_printf.c is_special.c print_c.c print_diu.c print_p.c print_percent.c print_s.c print_special.c print_xX.c put_hex.c
OBJS    = $(SRCS:.c=.o)

# Default rule: Build the library
all: $(NAME)

# Create the static library
$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS) $(LIBFT)

# Ensure libft.a is built
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) # Equivalent to cd libft && make

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	$(RM) $(OBJS)

# Remove object files and the library
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean # Runs fclean in libft/ 

# Rebuild everything
re: fclean all

# Phony targets (to prevent conflicts with files of the same name)
.PHONY: all clean fclean re

