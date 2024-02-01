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
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    // Successfull tests
    std::cout << "Successfull tests" << std::endl;
    try
    {
		//Successfull tests
		Intern intern = Intern();
		
		AForm *form1 = intern.makeForm("ShrubberyCreationForm", "home");
		std::cout << *form1 << std::endl;
		std::cout << "Target: " << (*form1).getTarget() << std::endl;
		AForm *form2 = intern.makeForm("RobotomyRequestForm", "home");
		std::cout << *form2 << std::endl;
		std::cout << "Target: " << (*form2).getTarget() << std::endl;
		AForm *form3 = intern.makeForm("PresidentialPardonForm", "home");
		std::cout << *form3 << std::endl;
		std::cout << "Target: " << (*form3).getTarget() << std::endl;
		//Unsuccessfull tests
		AForm *form4 = intern.makeForm("UnknowForm", "home");	
		(void) form4;
		// std::cout << *form4 << std::endl;
		// std::cout << "Target: " << (*form4).getTarget() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    return 0;
}
