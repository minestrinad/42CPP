/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:04:40 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 19:45:23 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>

class Base {
    public:
        virtual ~Base() { };
};

class A : public Base { };
class B : public Base { };
class C : public Base { };


Base *generate(void);
void identify(Base* p);
void identify(Base& p);

//                  **DIMONSTRATION WITH VIRTUAL FUNCTION GETTYPE**

// class Base {
//     public:
//         virtual ~Base() { };
    
//     virtual std::string getType() const = 0;
// };

// class A : public Base { 
//     public:
//         std::string getType() const { return ("A"); };
// };
// class B : public Base { 
//     public:
//         std::string getType() const { return ("B"); };
// };
// class C : public Base { 
//     public:
//         std::string getType() const { return ("C"); };
// };

// Base *generate(void);
// void identify(Base* p);
// void identify(Base& p);

#endif