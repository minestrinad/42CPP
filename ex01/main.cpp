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
#include "Form.hpp"

int main()
{
    // Successfull tests
    std::cout << "Successfull tests" << std::endl;
    try
    {
		//Successfull tests
		Bureaucrat bureaucrat("Bureaucrat1", 1);
		Form form("F1", 1, 1);
		bureaucrat.signForm(form);
		Form form2("F2", 100, 100);
		bureaucrat.signForm(form2);
		std::cout << std::endl;

		//Unsuccessfull tests
		Form form4("F4", 500, 500);
		Form form5("F5", 0, 0);
		Bureaucrat bureaucrat2("Bureaucrat2", 100);
		Form form3("F3", 1, 1);
		bureaucrat2.signForm(form3);
		bureaucrat2.signForm(form2);
		bureaucrat2.signForm(form4);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    return 0;
}
