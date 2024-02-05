/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:59:51 by everonel          #+#    #+#             */
/*   Updated: 2024/02/04 22:24:19 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchanger::BitcoinExchanger( ) : _dataMap(std::map<std::string, float>()) {
    std::fstream file;

    file.open("data.csv", std::ios::in);
    if (file.is_open() == false) {
        throw std::runtime_error("File not found");
    }
    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);
        if (line.size() > 0) {
            _dataMap[line.substr(0, DATE_SIZE)] = strtod(line.substr(DATE_SIZE + 1).c_str(), NULL);
        }
    }
}

BitcoinExchanger::BitcoinExchanger( const BitcoinExchanger& other ) { *this = other; }

BitcoinExchanger &BitcoinExchanger::operator=( const BitcoinExchanger& other ) {
    if (this != &other) {
        _dataMap = other._dataMap;
    }
    return *this;
}

// float   _validateQuery( const std::string& query ) {
//     std::istringstream iss(query);
//     std::string token;
//     std::getline(iss, token, '|');
//     std::cout << "token: " << token << std::endl;
//     // if (_dataMap.find(date) == _data.end()) {
//     //     throw std::runtime_error("Date not found");
//     // }  
//     // if (dollar < 0) {
//     //     throw std::runtime_error("Invalid amount");
//     // }
//     return 0;
// }

BitcoinExchanger::~BitcoinExchanger( ) { _dataMap.clear(); }


float   BitcoinExchanger::answerQuery(const std::string& query) {
    try {
        float originalValue = _validateQuery(query);
        std::cout << query << " => " << std::fixed << std::setprecision(2);
        std::cout << _dataMap[_findClosestDate(query.substr(0, 10))] * originalValue << std::endl;
        return originalValue;
    } catch (std::invalid_argument &e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "Runtime error: " << e.what() << std::endl;
    } catch (std::logic_error &e) {
        std::cout << "Logic error: " << e.what() << std::endl;
    }
    return 0;
}

float   BitcoinExchanger::_validateQuery( const std::string& query) {
    std::istringstream iss(query);
    std::string token;

    std::getline(iss, token, ' '); 
    _validateDate(token);

    std::getline(iss, token, ' ');
    if (token != "|")
        throw std::invalid_argument("Invalid format");
    
    std::getline(iss, token);
    float amount = _tryParseFloat<float>(token);
    if (amount < 0 || amount > 1000) 
        throw std::invalid_argument("Invalid amount");
    
    return amount;
}

void   BitcoinExchanger::_validateDate( const std::string& date ) {
    if (date.size() != DATE_SIZE) 
        throw std::invalid_argument("Invalid date");
    
    for (int i = 0; i < DATE_SIZE; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-') 
                throw std::invalid_argument("Invalid date");
        } else {
            if (date[i] < '0' || date[i] > '9') 
                throw std::invalid_argument("Invalid date");
        }
    }
}

template<typename T>T BitcoinExchanger::_tryParseFloat(const std::string& str) {
    std::istringstream iss(str);
    T value;

    iss >> value;
    if (iss.fail() == true) 
        throw std::invalid_argument("Invalid amount");

    return value;
}

std::string BitcoinExchanger::_findClosestDate(const std::string& str ) {
    std::string closestDate = "";
    std:map<std::string, float>::iterator it = _dataMap.begin();

    for (; it != _dataMap.end() && it->first < str; ++it) {
        closestDate = it->first;
    }
    return (it == _dataMap.end() ? closestDate : ((it + 1)->first - str < str - closestDate ? it->first : closestDate));
       
    std::cout << "Closest date: " << closestDate << std::endl;
    return closestDate;
}

int     BitcoinExchanger::_str2time( const std::string& str ) {
    std::string cleanDate = std::string(str);

    while ( int pos = cleanDate.find('-')){
        if (pos < 0) 
            break;
        cleanDate.erase(pos, 1);
    }

    return _tryParseFloat<double>(cleanDate);
}