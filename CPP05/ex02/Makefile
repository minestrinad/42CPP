NAME = ex02

SRCS = main.cpp \
      Bureaucrat.cpp \
	  AForm.cpp \
	  ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp \
	  PresidentialPardonForm.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	c++ -std=c++98 -Wall -Wextra -Werror $(OBJS) -o $(NAME)

%.o: %.cpp
	@echo "Compiling $<..."
	c++ -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -f $(OBJS)
	rm -f *_shrubbery

fclean: clean
	@echo "Fcleaning..."
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
