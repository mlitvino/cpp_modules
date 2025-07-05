CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17

NAME	= fight

SRC		= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

start: all
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re start
