//From Module 02 to Module 09, your classes must be designed in the Orthodox
//Canonical Form, except when explicitely stated otherwise.
//Canonical Form: https://web.archive.org/web/20150906155800/http://www.cplusplus.com/forum/articles/10627/
//Orthodox Canonical Form: https://web.archive.org/web/20150906155800/http://www.cplusplus.com/forum/articles/10627
// program has to compile with -std=c++98 -Wall -Wextra -Werror

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else{
        for (int i = 1; i < ac; i++){
            std::string str = av[i];
            for (size_t j = 0; j < str.length(); j++)
                std::cout << (char)std::toupper(str[j]);
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
