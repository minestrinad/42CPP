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

# test "9 2 4 1 7 3 5 6 0 10" "0 1 2 3 4 5 6 7 9 10 "

# test "2 3 0 1 4 5 6 7 9 10" "0 1 2 3 4 5 6 7 9 10 "

# test "10 5 2 6 12 9 1 11 3 8 4 7" "1 2 3 4 5 6 7 8 9 10 11 12 "

# test "1 2 3 4 14 5 6 13 7 8 9 10 11 12" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 "

# test "15 8 6 4 14 12 10 16 9 11 2 7 1 5 13 3" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 "

# test "1 2 12 9 14 8 6 4 17 10 7 16 3 13 15 5 11" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 "

test "4 5 2 11 10 15 1 17 3 12 13 19 9 14 6 7 16 18 8" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 "

# test "5 12 3 13 11 6 4 15 9 1 8 14 7 0 10" "0 1 3 4 5 6 7 8 9 10 11 12 13 14 15 "

test "17 14 9 10 7 13 18 15 16 3 8 12 4 1 11 2 6 5" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 "

# test "21 1 22 17 2 4 25 9 6 10 7 8 18 23 16 30 29 20 3 28 19 15 12 13 14 5 24 11 27 26" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 "

# test "66 17 27 53 21 11 39 62 67 32 16 44 89 78 58 5 99 46 63 72 47 87 73 30 18 81 75 42 50 28 55 76 91 77 64 71 60 29 92 61 8 26 1 37 14 43 79 52 36 23 40 100 48 6 20 70 57 4 31 25 65 90 45 22 12 49 83 56 84 69 98 2 94 80 74 68 96 82 13 59 9 19 51 85 86 88 15 10 54 34 41 3 7 95 35 24 38 33 93 97" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 "
echo "fastest.sh"
make fclean > /dev/null
