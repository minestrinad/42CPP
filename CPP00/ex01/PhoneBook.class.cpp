/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:20:06 by everonel          #+#    #+#             */
/*   Updated: 2023/10/24 18:47:43 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook() {
    _nbContacts = 0;
    _maxContacts = 0;
}

PhoneBook::~PhoneBook() {};

void PhoneBook::addContact(){
    Contact contact;
    contact = contact.createContact();
    if (_nbContacts >= MAX_CONTACTS){
        _contacts[_nbContacts % MAX_CONTACTS] = contact;
        _contacts[_nbContacts % MAX_CONTACTS].index = _nbContacts % MAX_CONTACTS;
    }
    else{
        _contacts[_nbContacts] = contact;
        _contacts[_nbContacts].index = _nbContacts;
        _maxContacts++;
    }
    _nbContacts++;
}

void PhoneBook::searchContact(){
    if (_nbContacts > 0){
        std::cout << BG_BOLD_ITALIC_CYAN <<"|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |"<< RESET << std::endl;
        for (int i = 0; i < _maxContacts; i++)
            _contacts[i].printInfoGeneric(_contacts[i]);
        std::string input;
        std::cout << BOLD_ITALIC_YELLOW <<"Choose an index to print info" << RESET << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof())
            exit(1);
        for (size_t i = 0; i < input.length(); i++)
            if (!std::isdigit(input[i]))
                return (std::cout << ITALIC_RED << ERR_NON_VALID << RESET, searchContact());
        if (std::atoi(input.c_str()) > _maxContacts -1)
            return (std::cout << ITALIC_RED << ERR_NON_VALID << RESET, searchContact());
        _contacts[std::atoi(input.c_str())].printInfo(_contacts[std::atoi(input.c_str())]);
    }
    else
        std::cout << ITALIC_RED << "No contact to show" << RESET << std::endl;
}
