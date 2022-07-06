NAME	=	libftprintf.a
LIBFT	=	libft.a
LDIR	=	libft/

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
AFLAGS	=	-rs
RM 		=	rm -rf

SRCS	=	ft_utoa.c ft_ptoa.c ft_printf.c ft_print_arg.c ft_itox.c \
			ft_get_mods.c ft_str_append.c ft_format.c
OBJS	=	$(SRCS:.c=.o)


# Targets
all: $(LDIR)/$(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LDIR)/$(LIBFT)
	@cp $(LDIR)$(LIBFT) $@
	@ar $(AFLAGS) $@ $(OBJS)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(LDIR)/$(LIBFT):
	@$(MAKE) -C $(LDIR)

bonus: all

# Removes objects
clean:
	@$(RM) $(OBJS)
	@$(RM) $(LDIR)*.o

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LDIR)$(LIBFT)

# Removes objects and executables and remakes
re: fclean all



# Removes debug files
dclean: fclean
	@$(RM) *.dSYM

# Test function used with main
test: $(LDIR)/$(LIBFT)
	@clear
	@$(CC) $(CFLAGS) -o test $(SRCS) test_printf.c $(LDIR)$(LIBFT)
	@./test
	@$(RM) test
