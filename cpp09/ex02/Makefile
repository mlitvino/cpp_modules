CC		= c++
CFLAGS	= -std=c++20 

#-Wall -Wextra -Werror

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
