/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:43:26 by everonel          #+#    #+#             */
/*   Updated: 2023/09/30 23:53:47 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define RESET		    "\033[0m"
#define ITALIC_RED      "\033[3;31m" 
#define ITALIC_BLUE     "\033[3;34m"
#define INPUT_ERROR     "Usage: <file_name> <s1> <s2>"
#define FILE_ERROR      "Something went wrong in file manipulation............."

std::string     file_name;
std::string     s1;
std::string     s2;

int main (int ac, char **av){
    // check for correct input
    if (ac != 4){
        std::cout << ITALIC_RED << INPUT_ERROR << RESET << std::endl;
        return 1;
    }

    // set variables
    file_name = av[1];
    s1 = av[2];
    s2 = av[3];
    std::string     line;
    size_t          pos; 
    std::ifstream   file(file_name);
    std::ofstream   tmpFile(".replace_" + file_name);
    if (!file.is_open() || !tmpFile.is_open())
        std::cout << ITALIC_RED << FILE_ERROR << RESET << std::endl;

    // change s1 to s2
    while (std::getline(file, line)){
        pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
        }
        tmpFile << line << std::endl;
    }
    file.close();
    tmpFile.close();
    
    // delete old file and rename new file
    if (remove(file_name.c_str()) != 0)
        std::cout << ITALIC_RED << "Error: File not deleted"<< RESET << std::endl;
    else if (rename((".replace_" + file_name).c_str(), file_name.c_str()) != 0)
        std::cout << ITALIC_RED << FILE_ERROR << RESET << "Error: File not renamed" << RESET << std::endl;
    else
    // print success
    std::cout << ITALIC_BLUE << "File updated" << RESET << std::endl;
    return 0;
}
