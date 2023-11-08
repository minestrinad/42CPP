/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:24:52 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:35:29 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

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