CC		= c++
CFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++17

NAME	= AAnimal

SRC		=	main.cpp Animal.cpp Dog.cpp Cat.cpp \
			WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ		= $(SRC:.cpp=.o)
INCL	=	Animal.hpp Dog.hpp Cat.hpp \
			WrongAnimal.hpp WrongCat.hpp Brain.hpp

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
