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


float BitcoinExchange::getRate(const std::string& date) const{

}

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
        
        float rateFloat = std::stof(rateStr);
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

bool BitcoinExchange::parseInput(std::string inputFile) {
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
        
        if (line.empty() || spPos1 == std::string::npos || slashPos == std::string::npos || spPos2 == std::string::npos || line == "date | value")
            throw std::runtime_error(RED"Error! Invalid input file."RES);

        else if (line == "date | value")
            continue;
            
        std::string indateStr = trimString(line.substr(0, spPos1));
        std::string invalueStr = trimString(line.substr(spPos2 + 1));
        
        if (!isValidDate(indateStr))
            throw std::runtime_error(RED"Error! Invalid date found in input file."RES);
        else if (!isValidRate(invalueStr))
            throw std::runtime_error(RED"Error! Invalid value found in input file."RES);

        
    }
}


bool BitcoinExchange::isValidDate(const std::string& date) {
    // 1. Format check YYYY-MM-DD (length 10, '-' at 4 and 7)
    // 2. Year between 2009 and current year (since Bitcoin didn’t exist before 2009)
    // 3. Month 1–12
    // 4. Day 1–31 (check depending on month, and leap years)
    // return true if all ok
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) {
    // Try to convert to float (catch exceptions)
    // Must be >= 0 and <= 1000
    // No alphabetic characters
    // return true if all ok
}