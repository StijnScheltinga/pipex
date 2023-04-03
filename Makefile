SOURCES	=		main.c parse_input.c create_process.c utils.c
SRC_DIR	=		src
BUILD	=		build
OBJECTS	=		$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME	=		pipex	
FLAGS	=		
CC		=		gcc

LIBS	=		lib/libft/libft.a
LIB_DIR	=		lib/libft
INCLUDE	=		-I lib/libft/libft.h -I inc/pipex.h

all: $(NAME)

$(NAME): $(OBJECTS)	$(LIBS)
	$(CC) $(flags) -o $(NAME) $(LIBS) $(OBJECTS)

$(BUILD)/%.o: $(SRC_DIR)/%.c | $(BUILD)
	gcc -g $(FLAGS) $(INCLUDE) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

$(LIBS):
	$(MAKE) -C lib/libft

clean:
	rm -rf $(OBJECTS) $(BUILD)
	$(MAKE) -C $(LIB_DIR) clean

fclean:
	rm -rf $(OBJECTS) $(NAME) $(BUILD)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all