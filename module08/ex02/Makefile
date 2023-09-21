SRC = main.cpp
NAME = MutantStack
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)

$(OBJ)/%.o: ./src/%.cpp
	g++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
