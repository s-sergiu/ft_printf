# binary name
NAME = libftprintf.a

# variables
SHELL=/bin/sh
VPATH=src

# flags
CFLAGS = -Wall -Wextra -Werror -Iinclude
ARFLAGS=rcs

# object files
OBJ = 	ft_printf.o \
		ft_itoa_unsigned.o \
		utils/printf_utils.o \
		utils/check_utils.o

# rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

# special built-in targets
.PHONY: bonus all clean fclean re
