CC		= c++ -g
CFLAGS	= -Wall -Wextra -Werror -std=c++20

NAME	= PmergeMe

SRC		=	main.cpp PmergeMe.cpp
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
