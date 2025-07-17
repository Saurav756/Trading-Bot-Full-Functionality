#include "../include/MarketDataHandler.h"
#include "../include/OrderManager.h"
#include "../include/RiskManager.h"
#include "../include/StrategyEngine.h"

#include <iostream>
#include <thread>

int main() {
    OrderManager om;
    RiskManager rm(50000);
    StrategyEngine strategy(om, rm);

    MarketDataHandler mdh;
    mdh.subscribe("AAPL", [&](const MarketData& data) {
        strategy.onMarketData(data);
    });

    std::thread marketThread([&]() {
        mdh.simulateData();
    });

    marketThread.join();
    return 0;
}
