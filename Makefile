# --------------------------------------------------
# Makefile template for building a static library
# Author: OZ
# --------------------------------------------------


#===================================================
#			VARIABLES
#===================================================

# Preprocessor
CPPFLAGS	= -I$(HDR_DIR)

# Compiler
CC		= cc
CFLAGS		= -Wall -Wextra -Werror

# Linker
LDFLAGS		=
LDLIBS		=

# Archiver
AR		= ar
ARFLAGS		= rcs

# Sources & objects
SRC_DIR		= src
SRC		= $(strip $(SRC_DIR)/ft_printf.c $(SRC_DIR)/is_special.c $(SRC_DIR)/print_c.c $(SRC_DIR)/print_diu.c	\
		  $(SRC_DIR)/print_p.c $(SRC_DIR)/print_percent.c  $(SRC_DIR)/print_s.c  $(SRC_DIR)/print_special.c	\
		  $(SRC_DIR)/print_xX.c $(SRC_DIR)/put_hex.c)

OBJ_DIR		= obj
OBJ		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Headers
HDR_DIR		= inc
HDR		= $(HDR_DIR)/ft_printf.h

# External library (libft)
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_OBJ	= $(LIBFT_DIR)/$(OBJ_DIR)/*.o

# File remover
RM		= rm
RMFLAGS		= -fr

# Default goal
NAME		= libftprintf.a

#===================================================
#			RULES
#===================================================

# Default goal set as phony target "all"
all : $(NAME)

# Static library creation
$(NAME) : $(OBJ) $(LIBFT)
	$(AR) $(ARFLAGS) $@ $(OBJ) $(LIBFT_OBJ)

# Creating libft object files
$(LIBFT) : | $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

# Compilation-only command
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HDR) | $(OBJ_DIR) 		# Don't forget header file as dependency
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 		# Whitespace forbidden between $(CPPFLAGS) and $(HDR_DIR)

# Object file directory creation
$(OBJ_DIR) :
	mkdir -p $@

# Clean rule
clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJ_DIR)

# Fclean rule
fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

# re rule
re : fclean all
	
# Phony target declaration directive
.PHONY: all clean fclean re
