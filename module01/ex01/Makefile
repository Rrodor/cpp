NAME= ZombieHorde
SRC= main.cpp Zombie.cpp zombieHorde.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	g++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

$(NAME): $(OBJ)
	g++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
