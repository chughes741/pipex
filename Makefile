
# Hides calls
VERBOSE	=	FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif


# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
DFLAG	=	-D DEBUG -Wall -Werror -Wextra
TFLAG	=	-pg -Wall -Werror -Wextra
RM		=	rm -rf


# Dir and file names
NAME	=	pipex
DEBUG	=	pipex_debug
TEST	=	pipex_test
LIBFT	=	libft.a
LDIR	=	libft/
SRCDIR	=	src/
SRCS	=	$(wildcard $(SRCDIR)*.c) # Change to file names before sub
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))


# Targets
all: $(LDIR)/$(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LDIR)/$(LIBFT)
	$(HIDE)$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDIR)$(LIBFT)

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

$(LDIR)/$(LIBFT):
	$(HIDE)$(MAKE) -C $(LDIR)


# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(TEST)
	$(HIDE)$(RM) $(DEBUG)
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(RM) *.dSYM
	$(HIDE)$(RM) *.out

# Removes objects and executables and remakes
re: fclean all


# Starts a debugging run
$(DEBUG): fclean
	$(HIDE)$(CC) $(DFLAG) -o $(DEBUG) $(SRCS) $(LDIR)$(LIBFT)

debug: $(DEBUG)
	$(HIDE)./$(DEBUG)

# Generates test files for valgrind and gprof
$(TEST): fclean
	$(HIDE)$(CC) $(TFLAG) -o $(TEST) $(SRCS) $(LDIR)$(LIBFT)

leak: $(TEST)
	$(HIDE)clear
	$(HIDE)valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all \
					--read-var-info=yes --read-inline-info=yes ./$(TEST)

time: $(TEST)
	$(HIDE)clear
	$(HIDE)./$(TEST)
	$(HIDE)gprof -b -p $(TEST) gmon.out
