#include <vector>
#include "OrderBookEntry.h"
#pragma once
#include "OrderBook.h"
class MerkelMain{
    public:
        MerkelMain();
        /**Call init to start sim */
        void init();
    private:
        void printMenu();
        void printHelp();
        void printMarket();
        void enterAsk();
        void enterBid();
        void printWallet();
        void nextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);
        
        std:: string currentTime;
        
        OrderBook OrderBook{"20200317.csv"};
};