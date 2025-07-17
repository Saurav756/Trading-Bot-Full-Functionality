#pragma once
#include "MarketDataHandler.h"
#include "OrderManager.h"
#include "RiskManager.h"
#include <deque>

class StrategyEngine {
public:
    StrategyEngine(OrderManager& om, RiskManager& rm, int shortWindow = 5, int longWindow = 20);

    void onMarketData(const MarketData& data);

private:
    void evaluateStrategy(double price);

    OrderManager& orderManager;
    RiskManager& riskManager;

    std::deque<double> shortWindowPrices;
    std::deque<double> longWindowPrices;
    int shortWindowSize;
    int longWindowSize;
    bool positionOpen = false;
    double currentExposure = 0.0;
};
