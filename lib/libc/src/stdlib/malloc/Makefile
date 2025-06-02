NAME = custom_alloc
SO_NAME = ./libft_malloc_x86_64_Linux.so
CC = clang
CFLAGS = -mavx2 -fPIC -fPIE -mprefer-vector-width=256 -fstack-protector -O3  -Wunused-function -Wunused-variable -Wunused 

LDFLAGS = -Wl
SRC = $(wildcard *.c)
OBJ_DIR = objs
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJ))

ifeq ($(DEBUG), true)
	CFLAGS += -D DEBUG
endif

all: $(OBJ_DIR) $(NAME) $(SO_NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -pie -o $(NAME) $(OBJ)

$(SO_NAME): $(OBJ_NO_MAIN)
	$(CC) -shared -fPIC $(LDFLAGS) -o $(SO_NAME) $(OBJ_NO_MAIN)

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME) $(SO_NAME)

re: fclean all

.PHONY: all clean fclean re
