CC		= c++
CFLAGS	= -Wall 						-Wextra -Wshadow -std=c++17

NAME	= AMateria

SRC		=	main.cpp AMateria.cpp Ice.cpp Cure.cpp \
			ICharacter.cpp Character.cpp
OBJ		= $(SRC:.cpp=.o)
INCL	=	AMateria.hpp Ice.hpp Cure.hpp \
			ICharacter.hpp Character.hpp

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
