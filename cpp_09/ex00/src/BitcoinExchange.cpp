/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:14 by icunha-t          #+#    #+#             */
/*   Updated: 2025/11/07 19:54:11 by isabeltooti      ###   ########.fr       */
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

    //check if database is openable
    if (!database.is_open())
        throw std::runtime_error(RED "Error! Couldn't open database file." RES);
    
    //check first line
    std::string line;
    std::getline(database, line);
    if (!line.empty() && line != "date,exchange_rate")
        throw std::runtime_error(RED"Error! Database file should start with \"date, exchange_rate\"." RES);
    line.clear();
    
    //read and copy line by line
    while (std::getline(database, line)){
        //find position of comma
        size_t commaPos = line.find(',');

        //if empty, comma or first line - jump loop
        if (line.empty() || commaPos == std::string::npos)
            continue;
        
        
        std::string dateStr = trimString(line.substr(0, commaPos)); //date
        std::string rateStr = trimString(line.substr(commaPos + 1)); //rate
        
        //parse date
        if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
            throw std::runtime_error(RED "Error! Invalid date found in database." RES);
        
        //convert rate to float
        float rateFloat = toFloat(rateStr);
        //parse rate
        if (rateFloat < 0)
            throw std::runtime_error(RED "Error! Invalid rate found in database." RES);
  
        //copy into db
        _db[dateStr] = rateFloat;
    }
    //close stream
    database.close();    
}


void BitcoinExchange::convert(std::string inputFile) {
    std::ifstream input(inputFile.c_str());
    
    if (!input.is_open())
        throw std::runtime_error(RED "Error! Couldn't open input file." RES);
    
    //check first line
    std::string line;
    std::getline(input, line);
    if (line != "date | value")
        throw std::runtime_error(RED "Error! Input file should start with \"date | value\"." RES);
    line.clear();

    //read and convert line by line
    while (std::getline(input, line)){
        size_t spPos1 = line.find(' '); //position of 1st space
        size_t slashPos = line.find('|'); //position of |
        size_t spPos2 = line.find(' ', spPos1 + 2); //position of 2nd space
        
        if (line.empty()){
            continue;
        }

        //look for syntax errors
        if (line == "date | value" || spPos1 == std::string::npos || slashPos == std::string::npos || spPos2 == std::string::npos){
            std::cerr << RED << "Error: bad input => " << RES << line << std::endl;
            continue;
        }
        
        std::string inDateStr = trimString(line.substr(0, spPos1)); //date
        std::string inValueStr = trimString(line.substr(spPos2 + 1)); //value to exchange
        
        //validate date and value
        if (!isValidDate(inDateStr))
            continue;
        else if (!isValidValue(inValueStr))
            continue;

        // get rate, convert value and calculate
        float rate = getRate(inDateStr);
        float value = toFloat(inValueStr);
        float result = value * rate;

        //print result
        std::cout << GRN << inDateStr << " => " << inValueStr << " = " << RES << result << std::endl;
    }
}

//INNER CLASS HELPERS
bool BitcoinExchange::isValidDate(const std::string& dateStr) {
    //check basics
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-'){
        std::cerr << RED << "Error: bad input => " << RES << dateStr << std::endl;
        return false;
    }
    
    //check if not digit
    for (size_t i = 0; i < dateStr.size(); i++){
        if (i == 4 || i == 7)
            continue;
            
        if (!isdigit((dateStr[i]))){
            std::cerr << RED << "Error: bad input => " << RES << dateStr << std::endl;
            return false;   
        }
    }

    //check date parts
    int year = toInt(dateStr.substr(0, 4));
    int month = toInt(dateStr.substr(5, 2));
    int day = toInt(dateStr.substr(8, 2));
    
    if (year < 2009 || year > 2025){
        std::cerr << RED << "Error: bad input => " << RES << "no information for year " << year << std::endl;
        return false;
    }
    else if (year < 0){
        std::cerr << RED << "Error: bad input => " << RES << dateStr << std::endl;
        return false;
    }
    else if (month < 1 || month > 12){
        std::cerr << RED << "Error: bad input => " << RES << dateStr << std::endl;
        return false;
    }
    else if (day < 1 || day > 31){
        std::cerr << RED << "Error: bad input => " << RES << dateStr << std::endl;
        return false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11 || month == 12) && day > 30){ //check months of 30
        std::cerr << RED << "Error: bad input => " << RES << dateStr << std::endl;
        return false;
    }
    else if (month == 2 && (year % 4 == 0) && day > 29){ //check feb leap year
        std::cerr << RED << "Error: bad input => " << RES << dateStr << std::endl;
        return false;
    }
    else if (month == 2 && (year % 4 != 0) && day > 28){ //check feb normal
        std::cerr << RED << "Error: bad input => " << RES << dateStr << std::endl;
        return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) {
    //basic char check
    for (size_t i = 0; i < valueStr.size(); i++){
        if ((valueStr[i] != '-' && valueStr[i] != '.' && valueStr[i] != ',')  && !isdigit((valueStr[i]))){
            std::cerr << RED << "Error: bad input => " << RES << valueStr << std::endl;
            return false;   
        }
    }
    
    //Convert to float
    float flValue = toFloat(valueStr);
    
    //check for negatives or above 10000 (subject rule)
    if (flValue < 0){
        std::cerr << RED << "Error: not a positive number." << RES << std::endl;
        return false;
    }
    if (flValue > 1000){
        std::cerr << RED << "Error: too large a number." << RES << std::endl;
        return false;
    }
    return true;
}

float BitcoinExchange::getRate(const std::string& date) const{
    if (_db.empty())
        throw std::runtime_error(RED "Error! Database is empty." RES);

    std::map<std::string, float>::const_iterator it = _db.lower_bound(date); //if no date finds immediately before
    
    //find in db - if date exists within the first column of map, return equivalent second
    if (it != _db.end() && it->first == date)
        return it->second;
    
    //if it is before the first date
    if (it == _db.begin())
        throw std::runtime_error(RED "Error! Date too early: no data available." RES);
    
    //if it's later than last date, return the last rate
    --it;
    return it->second;
}

const char* BitcoinExchange::invalidStrToFloat::what() const throw(){
	return "Error: Invalid input value => impossible to convert";
}

// OUTTER CLASS HELPERS
std::string trimString(std::string str){
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
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