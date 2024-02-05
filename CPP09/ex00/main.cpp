/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:40:16 by everonel          #+#    #+#             */
/*   Updated: 2024/02/04 02:34:50 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac , char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./btc [test_file]" << std::endl;
        return 1;
    }
    BitcoinExchanger exchanger = BitcoinExchanger();
    std::fstream file;

    file.open(av[1], std::ios::in);
    if (file.is_open() == false) {
        return std::invalid_argument("File not found"), 1;
    }

    bool isFirstLine = true;

    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);
        if (line.size() > 0) {
            if (isFirstLine) {
                isFirstLine = false;
                continue;
            }
            exchanger.answerQuery(line);
        }
    }
    return 0;
}
