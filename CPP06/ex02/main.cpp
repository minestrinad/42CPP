/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:09:17 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 19:47:02 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main (){
    srand(time(NULL));

    Base *base = generate();
    identify(base);
    identify(*base);
    //                  **DIMONSTRATION WITH VIRTUAL FUNCTION GETTYPE**
    // std::cout << base->getType() << std::endl;
    return (0);
}

