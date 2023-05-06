# Variables
NAME = microshell
CC = cc
# CFLAGS = -Wall -Wextra -Werror

EXEC_DIR = ./src/exec/
PARSING_DIR = ./src/parsing/
BIN_DIR = ./bin/
INCS = ./include/

# Mandatory files
FILES = $(EXEC_DIR)exec.c \
        $(EXEC_DIR)microshell.c \
        $(PARSING_DIR)parsing.c \


OBJ_FILES = $(FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS)

$(BIN_DIR)$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

all: $(BIN_DIR)$(NAME)

clean :
	rm -f $(OBJ_FILES)

fclean : 
	make clean
	rm -rf $(BIN_DIR)$(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
