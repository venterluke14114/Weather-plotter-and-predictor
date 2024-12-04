#include "CSVReader.h"
#include<iostream>
#include <fstream>

CSVReader::CSVReader()
{

}
std::vector<OrderBookEntry>CSVReader::readCSV(std::string csvFilename)
{
    std::vector<OrderBookEntry> entries;
    
    std::ifstream csvFile{csvFilename};
    std::string line;
    if (csvFile.is_open())
    {
        while(std::getline(csvFile, line))
        {
            try{
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
                entries.push_back(obe);
            }catch(const std::exception& e)
            {
                //std:: cout << "bad data in CSVReader::readCSV" << std:: endl;
            }
            
        }//end of while loop
    }
    std::cout << "CSVReader::readCSV " << entries.size() << std::endl;
    return entries;
    
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char seperator)
{
    std::vector<std::string> tokens;
    
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(seperator, 0);
    do{
        end = csvLine.find_first_of(seperator, start);
        if (start == csvLine.length() || start == end)break;
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
        start = end +1;
        }while(end != std::string::npos);
    
    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double price, amount;
    if(tokens.size() != 5)//error
    {
        //std::cout << "Bad line" << std::endl;
        throw std::exception{};
        
    }
            //we have 5 tokens
    try
    {
         price = std::stod(tokens[3]);
         amount = std::stod(tokens[4]);
    }catch(const std::exception& e)
    {
        std::cout << "CSVReader::stringsToOBE bad float " << tokens[3] << std::endl;
        std::cout << "CSVReader::stringsToOBE bad float " << tokens[4] << std::endl;
        throw;
    }
    OrderBookEntry obe{price, amount, tokens[0], tokens[1], OrderBookEntry:: stringToOrderBookType(tokens[2])};
    return obe;
}
OrderBookEntry CSVReader::stringsToOBE(
                                            std::string priceString,
                                            std::string amountString,
                                            std::string timestamp,
                                            std::string product,
                                            OrderBookType orderType)
{
    double price, amount;
    try
    {
         price = std::stod(priceString);
         amount = std::stod(amountString);
    }catch(const std::exception& e)
    {
        std::cout << "CSVReader::stringsToOBE bad float " << priceString[3] << std::endl;
        std::cout << "CSVReader::stringsToOBE bad float " << amountString[4] << std::endl;
        throw;
    }
    OrderBookEntry obe{price, amount, timestamp, product, orderType};
    return obe;
}