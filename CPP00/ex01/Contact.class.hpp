/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:14:27 by everonel          #+#    #+#             */
/*   Updated: 2023/09/18 19:33:20 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

class Contact
{
    private:
        std::string     _firstName;
        std::string     _lastName;
        std::string     _nickname;
        std::string     _phoneNumber;
        std::string     _darkestSecret;

        int             _controlInfo(std::string info, int type);
    public:
        int             index;

        Contact();
        ~Contact();
        Contact         createContact();
        std::string     setInfo(std::string info, int type);
        std::string     prepToPrint(std::string info);
        void            printInfoGeneric(Contact contact);
        void            printInfo(Contact contact);
};