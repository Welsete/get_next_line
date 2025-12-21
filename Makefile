# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME        = get_next_line.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

SRC         = get_next_line.c get_next_line_utils.c
OBJ         = $(SRC:.c=.o)
MAIN        = main.c
BIN         = gnl_test

# Default buffer size if none is specified
BUFFER_SIZE ?= 42

# Default test file if none is specified
TEST_FILE ?= tests/test1.txt

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "✅ Library compiled: $(NAME)"

# Generic test rule
run:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC) $(MAIN) -o $(BIN)
	@echo "🧪 Running with BUFFER_SIZE=$(BUFFER_SIZE) and file=$(TEST_FILE)"
	@./$(BIN) $(TEST_FILE)

# **************************************************************************** #
#                         CUSTOM SHORTCUTS FOR TESTS                           #
# **************************************************************************** #

# Format: make bX file
b%:
	@$(MAKE) BUFFER_SIZE=$* TEST_FILE=$(word 2, $(MAKECMDGOALS)) run

# Avoid errors for the second argument
%:
	@:

# **************************************************************************** #
#                                   CLEANUP                                    #
# **************************************************************************** #

clean:
	$(RM) $(OBJ)
	@echo "🧹 Object files removed."

fclean: clean
	$(RM) $(BIN) $(NAME)
	@echo "🧽 All binaries removed."

re: fclean all

.PHONY: all clean fclean re run
