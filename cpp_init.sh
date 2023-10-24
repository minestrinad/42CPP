#!/bin/bash

if [ $# -eq 0 ]
then
    echo "Enter a name for the project"
    read name
else
    name=$1
    shift
fi

# Create a directory for the project
mkdir -p $name && cd $name
touch main.cpp
touch Makefile
echo "NAME = $name

SRCS = main.cpp \\" >> Makefile
# Loop through the remaining arguments (class names) and create files for each
for class_name in "$@"; do
    touch "$class_name.cpp"
    touch "$class_name.hpp"

    echo "#include \"$class_name.hpp\"" >> main.cpp
    echo "      $class_name.cpp \\" >> Makefile
    echo "#include <iostream>

class $class_name
{
    private:

    public:

};" >> $class_name.hpp

    echo "#include \"$class_name.hpp\"

$class_name::$class_name() { }

$class_name::$class_name(const $class_name &src) { *this = src; }

$class_name::~$class_name() { }" >> $class_name.cpp
done


echo "
int main()
{
    return 0;
}" >> main.cpp

echo "
OBJS = \$(SRCS:.cpp=.o)

all: \$(NAME)

\$(NAME): \$(OBJS)
	@echo \"Compiling \$(NAME)...\"
	c++ -std=c++98 -Wall -Wextra -Werror \$(OBJS) -o \$(NAME)

%.o: %.cpp
	@echo \"Compiling \$<...\"
	c++ -std=c++98 -Wall -Wextra -Werror -c $< -o \$@

clean:
	@echo \"Cleaning...\"
	rm -f \$(OBJS)

fclean: clean
	@echo \"Fcleaning...\"
	rm -f \$(NAME)

re: fclean all

.PHONY : all clean fclean re" >> Makefile