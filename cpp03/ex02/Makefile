CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17

NAME	= FragTrap

SRC		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ		= $(SRC:.cpp=.o)
INCL	= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(INCL)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

start: all
	./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

%:
	@:

re: fclean all

.PHONY: all clean fclean re start
