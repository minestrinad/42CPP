/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:24:19 by everonel          #+#    #+#             */
/*   Updated: 2023/10/21 19:29:38 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else{
        for (int i = 1; i < ac; i++){
            std::string str = av[i];
            for (size_t j = 0; j < str.length(); j++)
                std::cout << (char)std::toupper(str[j]);
        }
    }
    std::cout << std::endl;
}
