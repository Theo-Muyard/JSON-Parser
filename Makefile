NAME		=	JSON.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	rcs

INCLUDES	=	-I includes/core
BUILD_DIR	=	build

SRC			=	JSON.c \
				core/fs.c \
				core/log.c
# 				core/parser.c

OBJ			=	$(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
CYAN		=	\033[36m
WHITE		=	\033[37m

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(YELLOW)Done$(WHITE)."

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "File $(GREEN)$(notdir $@)$(WHITE) builded."

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@echo "Directory $(BLUE)$(BUILD_DIR)$(WHITE) builded."

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(RED)Cleaned$(WHITE)."

fclean:
	@rm -rf $(BUILD_DIR) $(NAME) ./a.out
	@echo "$(RED)Fcleaned$(WHITE)."

re: fclean all

# TESTS

test_01:
	@$(CC) $(CFLAGS) tests/01/01.c $(NAME) $(INCLUDES)
	@./a.out

.PHONY: all clean fclean re test_01