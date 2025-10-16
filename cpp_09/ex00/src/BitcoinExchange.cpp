/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:14 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/16 00:16:24 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src): _db(src._db) {}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& src) {
    if (this != &src)
        this->_db = src._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDataBase(const std::string& dbFile) {
    std::ifstream database(dbFile.c_str());

    if (!database.is_open())
        throw std::runtime_error(RED"Error! Couldn't open database file."RES);
    
    std::string line;
    std::getline(database, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error(RED"Error! Database file should start with \"date, exchange_rate\"."RES);
    line.clear();
    while (std::getline(database, line)){
        size_t commaPos = line.find(',');
        if (line.empty() || commaPos == std::string::npos || line == "date,exchange_rate")
            continue;
        
        std::string dateStr = trimString(line.substr(0, commaPos));
        std::string rateStr = trimString(line.substr(commaPos + 1));
        
        if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
            throw std::runtime_error(RED"Error! Invalid date found in database."RES);
        float rateFloat = toFloat(rateStr);
        if (rateFloat < 0)
            throw std::runtime_error(RED"Error! Invalid rate found in database."RES);
  
        _db[dateStr] = rateFloat;
    }
    database.close();    
}

std::string BitcoinExchange::trimString(std::string str) const{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::convert(std::string inputFile) {
    std::ifstream input(inputFile.c_str());
    
    if (!input.is_open())
        throw std::runtime_error(RED"Error! Couldn't open input file."RES);
    
    std::string line;
    std::getline(input, line);
    if (line != "date | value")
        throw std::runtime_error(RED"Error! Input file should start with \"date | value\"."RES);
    line.clear();
    while (std::getline(input, line)){
        size_t spPos1 = line.find(' ');
        size_t slashPos = line.find('|');
        size_t spPos2 = line.find(' ', spPos1 + 2);
        
        if (line.empty()){
            continue;
        }

        if (line == "date | value" || spPos1 == std::string::npos || slashPos == std::string::npos || spPos2 == std::string::npos || line == "date | value"){
            std::cerr << "Bad input => " << line << std::endl;
            continue;
        } 
        std::string inDateStr = trimString(line.substr(0, spPos1));
        std::string inValueStr = trimString(line.substr(spPos2 + 1));
        
        if (!isValidDate(inDateStr))
            continue;
        else if (!isValidValue(inValueStr))
            continue;

        float rate = getRate(inDateStr);
        float value = toFloat(inValueStr);
        float result = value * rate;

        std::cout << inDateStr << " => " << inValueStr << " = " << result <<std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) {

    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-'){
        std::cerr << "Error: bad input => " << dateStr << std::endl;
        return false;
    }

    int year = toInt(dateStr.substr(0, 4));
    int month = toInt(dateStr.substr(5, 2));
    int day = toInt(dateStr.substr(8, 2));

    // if (!isalnum(year) || !isalnum(month) || !isalnum(day)){
    //      std::cerr << "Error: bad input => " << dateStr << std::endl;
    //     return false;
    // }
    else if (year < 2009 || year > 2025){
        std::cerr << "Error: bad input => no information for year " << year << std::endl;
        return false;
    }
    else if (year < 0){
        std::cerr << "Error: bad input => invalid year: " << dateStr << std::endl;
        return false;
    }
    else if (month < 1 || month > 12){
        std::cerr << "Error: bad input => invalid month: " << dateStr << std::endl;
        return false;
    }
    else if (day < 1 || day > 31){
        std::cerr << "Error: bad input => invalid day: " << dateStr << std::endl;
        return false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11 || month == 12) && day > 30){
        std::cerr << "Error: bad input => invalid day: " << dateStr << std::endl;
        return false;
    }
    else if (month == 2 && (year % 4 == 0) && day > 29){
        std::cerr << "Error: bad input => invalid day: " << dateStr << std::endl;
        return false;
    }
    else if (month == 2 && (year % 4 != 0) && day > 28){
        std::cerr << "Error: bad input => invalid day: " << dateStr << std::endl;
        return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) {

    float flValue = toFloat(valueStr);
    // if (!isalnum(static_cast<int>(flValue))){
    //      std::cerr << "Error: bad input => " << valueStr << std::endl;
    //     return false;
    // }
    if (flValue < 0){
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (flValue > 1000){
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

float BitcoinExchange::getRate(const std::string& date) const{
    if (_db.empty())
        throw std::runtime_error(RED"Error! Database is empty."RES);

    std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
    
    if (it != _db.end() && it->first == date)
        return it->second;
    
    if (it == _db.begin())
        throw std::runtime_error(RED"Error! Date too early: no data available."RES);
    
    --it;
    return it->second;
}

const char* BitcoinExchange::invalidStrToFloat::what() const throw(){
	return "Error: Invalid input value => impossible to convert ";
}

float toFloat(const std::string& str){
    std::stringstream ss(str);
    float f;
    ss >> f;
    return f;
}

int toInt(const std::string& str){
    std::stringstream ss(str);
    int i;
    ss >> i;
    return i;
}