#! /bin/bash

make re > /dev/null

echo "__________________"
./PmergeMe 9 2 4 1 7 3 5 6 0 10

echo "__________________"
./PmergeMe 5 12 3 13 11 6 4 15 9 1 8 14 7 0 10 
echo "__________________" 
make fclean > /dev/null
