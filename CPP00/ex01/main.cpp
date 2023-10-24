/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:23:22 by everonel          #+#    #+#             */
/*   Updated: 2023/10/20 13:34:58 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string input;

    while (input != "EXIT"){
        std::cout << BOLD_ITALIC_YELLOW <<"Choose if ADD, SEARCH or EXIT (make sure to typer the right input)" << RESET << std::endl;
        std::getline (std::cin, input, '\n');
        if(std::cin.eof())
            break;
        if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContact();
        else if (input != "EXIT")
            std::cout << BOLD_RED << "Wrong input, try again" << RESET << std::endl;
    }
}