/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:18:44 by everonel          #+#    #+#             */
/*   Updated: 2024/03/12 01:14:06 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<class T>void printContainer(const T &c)
{
    for (typename T::const_iterator it = c.begin(); it != c.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    try {
        if (ac < 3) {
            std::cerr << "Error: wrong number of arguments" << std::endl;
        }
        PmergeMe::validateInput(++av);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    // std::cout << "Before: ";
    PmergeMe PmergeMe(ac - 1, av);
    // printContainer<std::vector<int> >(PmergeMe.getVector());
    // std::vector<int> v = PmergeMe.getVector();

    // std::cout << "After:  ";
    // std::vector<PmergeMe::VIterator> vIters;

    // vIters.push_back(v.begin() + 2);
    // vIters.push_back(v.begin() + 3);
    // PmergeMe::VIterator end;
    // for (end = v.begin(); end != *(vIters.end() - 1); end++) { }
    // end++;
    // std::cout << "end: " << *end << std::endl;
    // PmergeMe::VIterator middle = end - 2;

    // std::rotate(v.begin(), middle, end);

    // printContainer<std::vector<int> >(v);
    // std::cout << "After:  ";
    int VTime = PmergeMe.PmergeVector( );
    // int LTime = PmergeMe.PmergeList( );
    printContainer<std::vector<int> >(PmergeMe.getVector());
    (void)VTime;
    
    // std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::vector : " << VTime / TIME_RESOLUTION << std::endl;
    // std::cout << "Time to process a range of " << LTime << " elements with std::list : " << PmergeMe.getListTime() << std::endl;
}