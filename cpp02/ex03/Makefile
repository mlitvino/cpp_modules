CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17

NAME	= BSP

SRC		= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ		= $(SRC:.cpp=.o)
INCL	= Fixed.hpp Point.hpp

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
