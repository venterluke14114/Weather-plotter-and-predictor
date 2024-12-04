#include<vector>
#include <iostream>
#include"MerkelMain.h"
#include"OrderBookEntry.h"
#include"CSVReader.h"
#include <limits>
MerkelMain::MerkelMain()
{

}
void MerkelMain::init()
{
    int input;
    currentTime = OrderBook.getEarliestTime();
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Help" << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an ask" << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid" << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet" << std::endl;
    // 6 continue
    std::cout << "6: Continue" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
}
void MerkelMain::printHelp()
{
    std::cout << "Help- your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}
void MerkelMain::printMarket()
{
    for(std::string const p : OrderBook.getKNownProducts())
    {
        std::cout << "products: " << p << std::endl;
        std::vector<OrderBookEntry> entries = OrderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks see: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    // std::cout << "OrderBook contains : " << orders.size()<< " entries"<< std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for(OrderBookEntry& e : orders)
    // {
    //     if (e.orderType == OrderBookType::ask)
    //     {
    //         asks ++;
    //     }
    //     if(e.orderType == OrderBookType::bid)
    //     {
    //         bids ++;
    //     }
    // }
    // std::cout << "asks: " << asks << " bids: " << bids << std::endl;
}
void MerkelMain::enterAsk()
{
    std::cout << "Make an ask- enter amount: product,price,amount eg: ETH/BTC,200, 0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::cout << "You typed: " << input << std::endl;
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if(tokens.size() != 3)
    {
        std::cout<< "Bad input! " << input << std::endl;
    }
    else{
        try{
        OrderBookEntry obe = CSVReader::stringsToOBE(
            tokens[1],
            tokens[2],
            currentTime,
            tokens[0],
            OrderBookType::ask
            
        );
        }catch(const std::exception& e){
            std::cout << "Bad Input: MerkelMain::enterAsk" << std::endl;
        }
    }
}
void MerkelMain::enterBid()
{
    std::cout << "Make a bid- enter amount" << std::endl;
}
void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
}
void MerkelMain::nextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
    currentTime = OrderBook.getNextTime(currentTime);
}
int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type 1-6" << std::endl;
    std::getline(std::cin, line);
    try{
    userOption = std::stoi(line);
    }catch(const std::exception& e)
    {
       //empty catch 
    }
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}
void MerkelMain::processUserOption(int userOption){
    if (userOption == 0 || userOption > 6) //bad input
    {
        std::cout << "Invalid. Choose 1-6" << std::endl;
    }
    if (userOption == 1) //bad input
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarket();
    }
    if (userOption == 3)
    {
        enterAsk();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        nextTimeFrame();
    }
}