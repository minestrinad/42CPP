/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:20:06 by everonel          #+#    #+#             */
/*   Updated: 2023/09/18 23:27:49 by everonel         ###   ########.fr       */
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
    if (_nbContacts >= 3){
        _contacts[_nbContacts % 3] = contact;
        _contacts[_nbContacts % 3].index = _nbContacts % 3;
    }
    else{
        _contacts[_nbContacts] = contact;
        _contacts[_nbContacts].index = _nbContacts;
        _maxContacts++;
    }
    _nbContacts++;
}

void PhoneBook::searchContact(){
    std::cout << BG_BOLD_ITALIC_CYAN <<"|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |"<< RESET << std::endl;
    for (int i = 0; i < _maxContacts; i++)
        _contacts[i].printInfoGeneric(_contacts[i]);
    std::cout << BOLD_ITALIC_YELLOW <<"Choose an index to print info" << RESET << std::endl;
    std::string input;
    std::getline(std::cin, input);
    if (std::stoi(input) >= _nbContacts)
        return (std::cout << ITALIC_RED << ERR_NON_VALID << RESET, searchContact());
    _contacts[std::stoi(input)].printInfo(_contacts[std::stoi(input)]);
}
