/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:04:49 by everonel          #+#    #+#             */
/*   Updated: 2023/10/27 00:35:25 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "str_address: " << &str << std::endl;
    std::cout << "ptr_address: " << &stringPTR << std::endl;
    std::cout << "ref_address: " << &stringREF << std::endl;

    std::cout << "str: " << str << std::endl;
    std::cout << "ptr: " << *stringPTR << std::endl;
    std::cout << "ref: " << stringREF << std::endl;
}