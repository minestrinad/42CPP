#! /bin/bash

define_colors()
{
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    NC='\033[0m'
}

make re

user_output="user_output.txt"

if [ ! -f ex00 ]
then
    echo "Makefile failed"
    exit 1
fi 

echo "Testing with literal characters" >> $user_output

./ex00 'e' > $user_output

./ex00 'l' >> $user_output

./ex00 'o' >> $user_output

./ex00 'H' >> $user_output

./ex00 'W' >> $user_output

./ex00 '{' >> $user_output
  
./ex00 ' ' >> $user_output

echo "Testing with literal integer" >> $user_output

./ex00 0 | cat -e >> $user_output

./ex00 -42 | cat -e >> $user_output

./ex00 42 | cat -e >> $user_output

echo "Testing with literal float" >> $user_output

./ex00 0.0f | cat -e >> $user_output

./ex00 -42.42f | cat -e >> $user_output

./ex00 42.42f | cat -e >> $user_output

./ex00 +inff | cat -e >> $user_output

./ex00 -inff | cat -e >> $user_output

./ex00 nanf | cat -e >> $user_output

echo "Testing with literal double" >> $user_output

./ex00 0.0 | cat -e >> $user_output

./ex00 -42.42 | cat -e >> $user_output

./ex00 42.42 | cat -e >> $user_output

./ex00 +inf | cat -e >> $user_output

./ex00 -inf | cat -e >> $user_output

./ex00 nan | cat -e >> $user_output

echo "Testing with empty string" >> $user_output

./ex00 "" | cat -e >> $user_output

echo "Testing with no arguments" >> $user_output

./ex00 | cat -e >> $user_output

echo "Testing with 1 argument" >> $user_output
 
./ex00 "Hello" | cat -e >> $user_output

echo "Testing with 2 arguments" >> $user_output

./ex00 "Hello" "World" | cat -e >> $user_output