/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 01:40:10 by everonel          #+#    #+#             */
/*   Updated: 2024/02/03 17:26:43 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

float   solveRPN( const std::string& exp) {
    std::stack<float> numberStack;
    std::istringstream iss(exp);
    std::string token;
    float a, b;

    while (iss >> token) {
        if (isOperator(token)) {
            if (numberStack.size() < 2 ){
                throw std::logic_error("Invalid Expression");
            }
            b = numberStack.top();
            numberStack.pop();
            a = numberStack.top();
            numberStack.pop();

            numberStack.push(calculate(a, b, token[0]));
        } else {
            int num = tryParseInt(token);
            if (num > 10) {
                throw std::invalid_argument("Number too large");
            }
            numberStack.push(num);
        }
    }
    if (numberStack.size() != 1) {
        throw std::logic_error("Invalid Expression");
    }
    return numberStack.top();
}

float   tryParseInt( std::string src ) {
    std::istringstream iss(src);
    int result;

    if (!(iss >> result)){
        throw std::invalid_argument("Conversion failed");
    }
    return result;
}

bool    isOperator(const std::string& str) {
    return ((str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/') && ((str[1]) ? std::isspace(str[1]) : true) );
}

float calculate( float a, float b, char op ) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;

        default: throw std::invalid_argument("Invalid operator");
    }
}
