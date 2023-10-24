/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:54:53 by everonel          #+#    #+#             */
/*   Updated: 2023/10/13 02:13:15 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define BLACK  "\033[1;30m"      /* Black */
#define RED    "\033[1;31m"      /* Red */
#define GREEN  "\033[1;32m"      /* Green */
#define YELLOW "\033[1;33m"      /* Yellow */
#define BLUE   "\033[1;34m"      /* Blue */
#define MAGENTA "\033[1;35m"     /* Magenta */
#define CYAN   "\033[1;36m"      /* Cyan */
#define WHITE  "\033[1;37m"      /* White */

// Do you know Harl? We all do, do we? In case you don’t, find below the kind of
// comments Harl makes. They are classified by levels:
//      •"DEBUG" level: Debug messages contain contextual information. They are mostly
//          used for problem diagnosis.
//          Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-
//          ketchup burger. I really do!"
//      •"INFO" level: These messages contain extensive information. They are helpful for
//          tracing program execution in a production environment.
//          Example: "I cannot believe adding extra bacon costs more money. You didn’t put
//          enough bacon in my burger! If you did, I wouldn’t be asking for more!"
//      •"WARNING" level: Warning messages indicate a potential issue in the system.
//          However, it can be handled or ignored.
//          Example: "I think I deserve to have some extra bacon for free. I’ve been coming for
//          years whereas you started working here since last month."
//      •"ERROR" level: These messages indicate an unrecoverable error has occurred.
//          This is usually a critical issue that requires manual intervention.
//          Example: "This is unacceptable! I want to speak to the manager now."


// You are going to automate Harl. It won’t be difficult since it always says the same
// things. 
//      You have to create a Harl class with the following private member functions:
//          •void debug( void );
//          •void info( void );
//          •void warning( void );
//          •void error( void );
// Harl also has a public member function that calls the four member functions above
// depending on the level passed as parameter:
//      void complain( std::string level );
// The goal of this exercise is to use pointers to member functions. This is not a
// suggestion. 
// Harl has to complain without using a forest of if/else if/else. It doesn’t think twice!
// 
// Create and turn in tests to show that Harl complains a lot. You can use the examples
// of comments listed above in the subject or choose to use comments of your own.

int main (){
    Harl harl;
    // write in different colors depending on the level
    // write in blue for INFO, green for DEBUG, yellow for WARNING and red for ERROR
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

