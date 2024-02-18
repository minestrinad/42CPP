
echo "
____________________________________  ________  ______________________ _________________________________________ 
\_   ___ \______   \______   \   _  \/   __   \ \__    ___/\_   _____//   _____/\__    ___/\_   _____/\______   \
/    \  \/|     ___/|     ___/  /_\  \____    /   |    |    |    __)_ \_____  \   |    |    |    __)_  |       _/
\     \___|    |    |    |   \  \_/   \ /    /    |    |    |        \/        \  |    |    |        \ |    |   \
 \______  /____|    |____|    \_____  //____/     |____|   /_______  /_______  /  |____|   /_______  / |____|_  /
        \/                          \/                             \/        \/                    \/         \/ 
"

// choose the exercise you want to test
echo "Choose the exercise you want to test: "
echo "00 - BitcoinExchange"
echo "01 - RPN"
echo "02 - PmergeMe"
echo "03 - All exercises"

read exercise

if [ $exercise -eq 00 ]
then
    echo "Testing BitcoinExchange"
    sh ./BitcoinExchange_tester.sh
elif [ $exercise -eq 01 ]
then
    echo "Testing RPN"
    sh ./RPN_tester.sh
elif [ $exercise -eq 02 ]
then
    echo "Testing PmergeMe"
    sh ./PmergeMe_tester.sh
elif [ $exercise -eq 03 ]
then
    echo "Testing all exercises"
    sh ./BitcoinExchange_tester.sh
    sh ./RPN_tester.sh
    sh ./PmergeMe_tester.sh
else
    echo "Invalid input"
fi