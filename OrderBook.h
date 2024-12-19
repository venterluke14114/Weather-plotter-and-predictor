#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include<string>
#include<vector>

class OrderBook
{
    public:
        /**construct, reading a csv data file */
        OrderBook(std::string filename);
        /**return vector of all known products in dataset */
        std::vector<std::string> getKNownProducts();
        /**return vectors of Orders acording to set filters */
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
        std::string product,
        std::string timestamp);
        /** returns earliest time*/
        std::string getEarliestTime();
        /**returns next time after sent time
         * If no next timestamp, wrap arounds to start
         */
        std::string getNextTime(std::string timestamp);
        void insertOrder(OrderBookEntry& order);

        std::vector<OrderBookEntry> MatchAsksToBids(std::string product, std::string timesamp);

        static double getHighPrice
        (std::vector<OrderBookEntry>& orders);
        static double getLowPrice
        (std::vector<OrderBookEntry>& orders);
        private:
            std::vector<OrderBookEntry> orders;


};