/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:29:26 by emma              #+#    #+#             */
/*   Updated: 2023/11/19 16:03:31 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // Successfull tests
    std::cout << "Successfull tests" << std::endl;
    try
    {
		Bureaucrat b1("B1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("B2", 150);
		std::cout << b2 << std::endl;
		Bureaucrat b3("B3", 42);
		std::cout << b3 << std::endl;

		std::cout << "Succesfull increment / decrement" << std::endl;
		b3.incrementGrade();
		std::cout << b3 << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;

		std::cout << "Unsuccesfull increment / decrement" << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;

		std::cout << "Unsuccessfull tests" << std::endl;
		Bureaucrat b4("B4", 0);
		std::cout << b1 << std::endl;
		Bureaucrat b5("B5", 151);
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    return 0;
}
