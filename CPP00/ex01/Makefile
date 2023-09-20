NAME = MyAwesomePhoneBook

SRCS = 	main.cpp \
		PhoneBook.class.cpp \
		Contact.class.cpp

OBJS = $(SRCS:.cpp=.o)

CPP_FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	c++ $(CPP_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@echo "Compiling $<..."
	c++ $(CPP_FLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -f $(OBJS)

fclean: clean
	@echo "Fcleaning..."
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re