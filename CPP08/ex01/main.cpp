/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:57:14 by everonel          #+#    #+#             */
/*   Updated: 2024/02/08 21:25:52 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <fstream>

# include <cstdlib>

int main( )
{
    int MAX_NUM = 100000;
    std::vector<int> vec;

    for (int i = 0; i < MAX_NUM; i++){
        int num = rand() % 500;
        vec.push_back(num);
    }

    Span sp = Span(MAX_NUM);
    
    sp.addMoreNumbers(vec);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}