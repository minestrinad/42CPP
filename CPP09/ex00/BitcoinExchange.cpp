/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:59:51 by everonel          #+#    #+#             */
/*   Updated: 2024/02/19 12:24:40 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchanger::BitcoinExchanger( ) : _dataMap(std::map<int, float>()) {
    try {
        _loadData();
    } catch (std::runtime_error &e) {
        std::cout << "Runtime error: " << e.what() << std::endl;
    }
}

BitcoinExchanger::BitcoinExchanger( const BitcoinExchanger& other ) { *this = other; }

BitcoinExchanger &BitcoinExchanger::operator=( const BitcoinExchanger& other ) {
    if (this != &other) {
        _dataMap = other._dataMap;
    }
    return *this;
}

BitcoinExchanger::~BitcoinExchanger( ) { _dataMap.clear(); }

float   BitcoinExchanger::answerQuery(const std::string& query) {
    try {
        float originalValue = _validateQuery(query);
        std::cout << query << " => ";
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

void    BitcoinExchanger::_loadData( ) {
    std::fstream file;

    file.open(DATABASE, std::ios::in);
    if (file.is_open() == false) {
        throw std::runtime_error("Database file not found");
    }
    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);
        if (line.size() > 0) {
            _dataMap[_str2time(line.substr(0, DATE_SIZE))] = strtod(line.substr(DATE_SIZE + 1).c_str(), NULL);
        }
    }
    file.close();
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
    float amount = _tryParseFloat(token);
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

float BitcoinExchanger::_tryParseFloat(const std::string& str) {
    std::istringstream iss(str);
    float value;

    iss >> value;
    if (iss.fail() == true) 
        throw std::invalid_argument("Conversion failed");

    return value;
}

int BitcoinExchanger::_findClosestDate( const std::string& str ) {
    std::map<int, float>::iterator it = _dataMap.begin();
    int date = _str2time(str);
    int closestDate;

    if (_dataMap[date] != 0)
        return date;

    for (; it != _dataMap.end() && it->first < date; ++it) {
        closestDate = it->first;
    }

    if (it != _dataMap.end()){
        it++;
        if (it->first - date < date - closestDate){
            closestDate = it->first;
        }
    }
    return closestDate;
}

int BitcoinExchanger::_str2time( const std::string& str ) {
    int time = 0;
    int mult = 1;

    for (int i = DATE_SIZE - 1; i >= 0; i--) {
        if (str[i] != '-') {
            time += (str[i] - '0') * mult;
            mult *= 10;
        }
    }
    return time;
}