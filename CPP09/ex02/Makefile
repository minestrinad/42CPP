NAME = PmergeMe

SRCS = main.cpp \
		PmergeMe.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	c++ -g -std=c++98 -Wall -Wextra -Werror  $(OBJS) -o $(NAME)

%.o: %.cpp
	@echo "Compiling $<..."
	c++ -g -std=c++98 -Wall -Wextra -Werror  -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -f $(OBJS)

fclean: clean
	@echo "Fcleaning..."
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
