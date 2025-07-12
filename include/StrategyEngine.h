#pragma once
#include "MarketDataHandler.h"
#include "OrderManager.h"
#include <deque>

class StrategyEngine {
public:
    StrategyEngine(OrderManager& om, int shortWindow = 5, int longWindow = 20);

    void onMarketData(const MarketData& data);

private:
    void evaluateStrategy(double price);

    OrderManager& orderManager;
    std::deque<double> shortWindowPrices;
    std::deque<double> longWindowPrices;
    int shortWindowSize;
    int longWindowSize;
    bool positionOpen = false;
};
