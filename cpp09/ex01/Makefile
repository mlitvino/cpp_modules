CC		= c++
CFLAGS	= -Wall -Wextra -std=c++20

NAME	= RPN

SRC		=	main.cpp RPN.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

.SECONDARY: $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

start: all clean
	./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

%:
	@:

re: fclean all

.PHONY: all clean fclean re start
