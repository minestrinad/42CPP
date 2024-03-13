#! /bin/bash

test() {
    echo "______________________________"
    local input="$1"
    local expected="$2"
    local output=$(./PmergeMe $input)

    echo "______________________________"
    echo "Input:    $input"
    echo "Size:     $(echo $input | wc -w)"
    echo ""
    echo "Output:   $output"
    echo "Expected: $expected"
    echo ""
    if [ "$output" = "$expected" ]; then
        echo "✅Test passed"
    else
        echo "⛔Test failed"
    fi
}


make re > /dev/null

test "9 2 4 1 7 3 5 6 0 10" "0 1 2 3 4 5 6 7 9 10 "

test "2 3 0 1 4 5 6 7 9 10" "0 1 2 3 4 5 6 7 9 10 "

test "10 5 2 6 12 9 1 11 3 8 4 7" "1 2 3 4 5 6 7 8 9 10 11 12 "

test "1 2 12 9 14 8 6 4 17 10 7 16 3 13 15 5 11" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 "

test "15 8 6 4 14 12 10 16 9 11 2 7 1 5 13 3" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 "

test "4 5 2 11 10 15 1 17 3 12 13 19 9 14 6 7 16 18 8" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 "

test "5 12 3 13 11 6 4 15 9 1 8 14 7 0 10" "0 1 3 4 5 6 7 8 9 10 11 12 13 14 15 "

echo "fastest.sh"
make fclean > /dev/null
