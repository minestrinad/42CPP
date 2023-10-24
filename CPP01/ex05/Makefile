NAME = harl

SRCS = Harl.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[32mCompiling $(NAME)...\033[0m"
	c++ -std=c++98 -Wall -Wextra -Werror $(OBJS) -o $(NAME)

%.o: %.cpp

	@echo "\033[32mCompiling $<...\033[0m"
	c++ -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@echo "\033[33mCleaning $(NAME)...\033[0m"
	rm -f $(OBJS)

fclean: clean
	@echo "\033[33mFcleaning...\033[0m"
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re