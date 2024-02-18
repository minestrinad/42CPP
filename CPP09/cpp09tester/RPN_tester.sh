#! /bin/bash


clear
echo -n "Running RPN test" 
# Display the dots one by one and then erase them
for i in {1..2}; do
    echo -n " ."
    sleep 0.25
    echo -n " ."
    sleep 0.25
    echo -n " ." 
    sleep 0.25
done &

(cd ../ex01 && make re > /dev/null) & wait

cd ../ex01

test(  ) {
    local expression=$1
    local expected=$2
    ./RPN "$expression" > output.txt
    echo "______________________________"
    echo "Expression: $expression"
    local output=$(cat output.txt)
    if [ $output -eq $expected ]
    then #write test passed in green
        echo "\033[0;32m✅Test passed\033[0m"
    else
        echo "\033[0;31m⛔Test failed\033[0m"
    fi
    echo "Output: $output"
    echo "Expected: $expected"
    echo "______________________________"
}

echo "\033[1;32m

  __              _                 
 (    _ _ _  _  _(_   //   _/_  __/ _ 
__)(/( ( (-_) _) / (/((    /(-_) /_)  
______________________________________                                    

\033[0m"
test "1 1 +" 2
test "1 1 -" 0
test "1 3 5 + -" -7
test "8 9 * 9 - 9 - 9 - 4 - 1 +" 42
test "7 7 * 7 -" 42
test "1 2 * 2 / 2 * 2 4 - +" 0
test "1 2 3 4 5 6 7 8 9 10 + + + + + + + + +" 55
test "5" 5
echo "\033[1;31m

                        _                 
 /  /   _   _ _ _  _  _(_   //   _/_  __/ _ 
(__//)_) (/( ( (-_) _) / (/((    /(-_) /_)  
____________________________________________                                          

\033[0m"
test "(1 + 1)" "Invalid argument: Conversion failed"
test "+" "Logic error: Invalid Expression"
test "" "Logic error: Invalid Expression"
test "1 1 + 1" "Logic error: Invalid Expression"
test "1 1 + +" "Logic error: Invalid Expression"
test "1 0 /" "Error: Division by zero"

cd ../ex01 && make fclean > /dev/null && cd ../cpp09tester
echo "RPN test completed"
