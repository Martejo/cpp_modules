NAME	=	Materia

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -Wshadow -std=c++98

SRCS	=	main.cpp \
			AMateria.cpp \
			Character.cpp \
			Cure.cpp	 \
			Ice.cpp	 \
			MateriaSource.cpp \

OBJ		=	$(SRCS:.cpp=.o)

INC		=	ICharacter.hpp\
			AMateria.hpp \
			Character.hpp \
			Cure.hpp	 \
			Ice.hpp	 \
			MateriaSource.hpp \
			IMateriaSource.hpp

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
	@echo -n "$(YELLOW)Compiling $(BOLD)$(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)\nDone.$(RESET)\n"

%.o: %.cpp $(INC)
	@echo "$(CYAN)Creating object file for $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Finished $@$(RESET)\n"

clean:
	@echo -n "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ)
	@echo "$(GREEN)\nObject files cleaned.$(RESET)\n"

fclean: clean
	@echo -n "$(RED)Removing executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)\nExecutable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
