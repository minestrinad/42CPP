#! /bin/bash

make re

echo "Test 1"
./RPN "1 2 +"
echo "Expected: 3"

echo "Test 2"
./RPN "1 2 + 3 *"
echo "Expected: 9"

echo "Test 3"
./RPN "1 2 3 * +"
echo "Expected: 7"

echo "Test 4"
./RPN "1 2 3 * + 4 -"
echo "Expected: 3"

echo "Test 5"
./RPN "1 2 3 * + 4 - 5 /"
echo "Expected: 0.6"

echo "Test 6"
./RPN "1 2 3 * + 4 - 5 / 6 +"
echo "Expected: 6.6"

echo "Test 7"
./RPN "1 2 3 * + 4 - 5 / 6 + 7 -"
echo "Expected: -0.4"

echo "Test 8"
./RPN "1 2 3 * + 4 - 5 / 6 + 7 - 8 *"
echo "Expected: -3.2"

echo "Test 9"
./RPN "1 2 3 * + 4 - 5 / 6 + 7 - 8 * 9 /"
echo "Expected: 0.355556"

echo "Test 10"
./RPN "1 2 3 * + 4 - 5 / 6 + 7 - 8 * 9 / 10 +"
echo "Expected: 9.64444"

echo "Test 11"
./RPN "1 2 3 4 5 6 7 8 9 10 + + + + + + + + +"
echo "Expected: 55"

echo "Test 12"
./RPN "1 2 3 4 5 6 7 8 9 10 + + + + + + + + + 11 +"
echo "Expected: number too large"

echo "Test 13"
./RPN "1 2 3 4 5 6 7 8 9 10 + + + + + + + + + +"
echo "Expected: invalid expression"

echo "Test 14"
./RPN "1 2 3 4 5 6 7 8 9 10 + + "
echo "Expected: invalid expression"

