NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = 	main.cpp \
	AMateria.cpp \
	Character.cpp \
	Ice.cpp \
	Cure.cpp \
	MateriaSource.cpp \

MAKE = make
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: test

test: re
	@echo "Running tests..."
	./$(NAME)
	$(MAKE) fclean

.PHONY: all clean fclean re test run
