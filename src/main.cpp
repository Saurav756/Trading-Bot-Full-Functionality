#include "../include/MarketDataHandler.h"
#include <iostream>

void onMarketData(const MarketData& data) {
    std::cout << "Symbol: " << data.symbol << " Price: " << data.price << " Time: " << data.timestamp << '\n';
}

int main() {
    MarketDataHandler mdh;
    mdh.subscribe("AAPL", onMarketData);
    mdh.simulateData();
    return 0;
}
