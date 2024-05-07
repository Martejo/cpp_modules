NAME	=	FightSimulator

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp \
			HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp \

INC		=	HumanA.hpp \
			HumanB.hpp \
			Weapon.hpp \
		

OBJ		=	$(SRCS:.cpp=.o)

RM		=	rm -rf

#Colors and styles:
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[0;36m
RESET	= \033[0m
BOLD	= \033[1m
UNDERLINE = \033[4m

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n "$(CYAN)Compiling $(BOLD)$(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)\nDone.$(RESET)"

%.o: %.cpp $(INC)
	@echo "$(CYAN)Creating object file for $<...$(RESET)"
	@$(CC) $(CFLAGS) -I ./ -c $< -o $@
	@echo "$(GREEN)Finished $@\n$(RESET)"

clean:
	@echo -n "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ)
	@echo "$(GREEN)\nObject files cleaned.\n$(RESET)"

fclean: clean
	@echo -n "$(RED)Removing executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)\nExecutable removed.\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re