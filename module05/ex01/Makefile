NAME		= Forms

CC			= c++

CFLAGS		= -std=c++98 -g3 -Wall -Wextra -Werror -Wshadow 

SRC_FILES 	=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp \

OBJ			= $(SRC_FILES:.cpp=.o)

INC 		=	Bureaucrat.hpp \
				Form.hpp \


%.o   : %.cpp $(INC)
	${CC} ${CFLAGS} -c $< -o $@ -I.

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n Compiling executable $(NAME)...
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo Done.

clean:
	@echo -n Making clean...
	@rm -rf $(OBJ)
	@echo Done.

fclean: clean
	@echo -n Making fclean...
	@rm -f $(NAME)
	@echo Done.

test: re
	./$(NAME)
	@make fclean

re: fclean all

.PHONY : all clean fclean re test