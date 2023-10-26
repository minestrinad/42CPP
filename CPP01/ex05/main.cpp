/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:54:53 by everonel          #+#    #+#             */
/*   Updated: 2023/10/27 00:59:23 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (){
    Harl harl;
    std::cout << "\033[1;36m" << std::endl;
    harl.complain("INFO");;
    std::cout << "\033[1;32m" << std::endl;
    harl.complain("DEBUG");
    std::cout << "\033[1;33m" << std::endl;
    harl.complain("WARNING");
    std::cout << "\033[1;31m" << std::endl;
    harl.complain("ERROR");
    std::cout << "\033[0m" << std::endl;
}

