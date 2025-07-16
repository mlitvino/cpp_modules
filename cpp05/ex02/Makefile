CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17

NAME	= Executor

SRC		=	main.cpp Bureaucrat.cpp AForm.cpp \
			PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
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
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re start
