CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17

NAME	= Identify

SRC		=	main.cpp Base.cpp
OBJ		= $(SRC:.cpp=.o)

.SECONDARY: $(OBJ)

all: $(NAME)

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
