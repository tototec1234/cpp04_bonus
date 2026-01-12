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
OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
OBJS_WITH_DIR = $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_WITH_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS_WITH_DIR) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

re: fclean all

run: test

test: re
	@echo "Running tests..."
	./$(NAME)
	$(MAKE) fclean

test-clean: re
	@echo "Running tests (stderr suppressed)..."
	./$(NAME) 2>/dev/null
	$(MAKE) fclean

.PHONY: all clean fclean re test test-clean run
