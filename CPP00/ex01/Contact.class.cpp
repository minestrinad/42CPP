/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:19:56 by everonel          #+#    #+#             */
/*   Updated: 2023/09/18 23:24:53 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"


int     Contact::_controlInfo(std::string info, int type){
    if (info.empty())
        return 0;
    if (type == TEXT_INFO){
        for (int i = 0; i < (int)info.length(); i++){
            if ((info[i] < 'a' || info[i] > 'z') && (info[i] < 'A' || info[i] > 'Z'))
                return 0;
        }
    }
    else if (type == NUMBER_INFO){
        if (info.length() != 10)
            return 0;
        for (int i = 0; i < 10; i++){
            if (info[i] < '0' || info[i] > '9')
                return 0;
        }
    }
    return 1;
}

std::string     Contact::prepToPrint(std::string info){
    if (info.length() > 10)
        info = info.substr(0, 9) + ".";
    else if (info.length() < 10)
        info = info + std::string(10 - info.length(), ' ');
    return info;
}

Contact::Contact() {};

Contact::~Contact() {};

std::string Contact::setInfo(std::string request, int type){
    std::string input;
    std::cout << request;
    std::getline(std::cin, input);
    if (_controlInfo(input, type) == 0)
        return (std::cout << ITALIC_RED << ERR_NON_VALID << RESET, setInfo(request, type));
    return input;
}

Contact Contact::createContact(){
    Contact contact;

    contact._firstName = setInfo("First Name: ", TEXT_INFO);
    contact._lastName = setInfo("Last Name: ", TEXT_INFO);
    contact._nickname = setInfo("Nickname: ", OTHER_INFO);
    contact._phoneNumber = setInfo("Phone Number: ", NUMBER_INFO);
    contact._darkestSecret = setInfo("Darkest Secret: ", OTHER_INFO);
    return contact;
}

void Contact::printInfoGeneric(Contact contact){
    std::cout << "|" << prepToPrint(std::to_string(contact.index)) 
        << "|" << prepToPrint(contact._firstName) << "|" << prepToPrint(contact._lastName) 
        << "|" << prepToPrint(contact._nickname) << "|" << std::endl;
}

void    Contact::printInfo(Contact contact){
    std::cout << "First Name:     " << contact._firstName << std::endl;
    std::cout << "Last Name:      " << contact._lastName << std::endl;
    std::cout << "Nickname:       " << contact._nickname << std::endl;
    std::cout << "Phone Number:   " << contact._phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << contact._darkestSecret << std::endl;
}
