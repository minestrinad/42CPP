/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:19:06 by everonel          #+#    #+#             */
/*   Updated: 2023/09/18 23:14:54 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"
# include "includes.h"
# include "colors.h"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _nbContacts;
        int     _maxContacts;
    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    searchContact();
};

#endif