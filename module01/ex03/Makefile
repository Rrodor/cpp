NAME= war
SRC= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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
