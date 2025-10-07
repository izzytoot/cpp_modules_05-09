/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:14 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/03 12:40:00 by icunha-t         ###   ########.fr       */
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

bool BitcoinExchange::isValidDate(const std::string& date) {

}

bool BitcoinExchange::isValidRate(const std::string& rateStr, float& rateFloat) {

}

void BitcoinExchange::loadDataBase(const std::string& filename) {
    std::ifstream database(filename.c_str());

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
        
        if (!isValidDate(dateStr))
            throw std::runtime_error(RED"Error! Invalid date found in database."RES);
        
        float rateFloat = std::stof(rateStr);
        if (!isValidRate(rateStr, rateFloat))
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

bool BitcoinExchange::parseInput(std::string fname) {

}
