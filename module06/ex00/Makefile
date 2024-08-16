NAME		= scalar_converter

CC			= c++

CFLAGS		= -std=c++98 -g3 -Wall -Wextra -Werror

SRC_FILES 	=	main.cpp \
				ScalarConverter.cpp \
				ScalarConverterUtils.cpp \
				ScalarConverterExceptions.cpp \

OBJ			= $(SRC_FILES:.cpp=.o)

INC 		=	ScalarConverter.hpp \
				

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