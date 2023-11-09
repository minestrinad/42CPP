/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:24:52 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 22:53:13 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

# define RESET      "\033[0m"
# define DEBUG		"\033[33m"

class Brain 
{
    public:
        Brain( );
        Brain( Brain &);
        ~Brain( );

        Brain &operator=( Brain & );
    private:
        std::string _ideas[100];
};

#endif