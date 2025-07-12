#include "../include/StrategyEngine.h"

StrategyEngine::StrategyEngine(OrderManager& om, int shortW, int longW)
    : orderManager(om), shortWindowSize(shortW), longWindowSize(longW) {}

void StrategyEngine::onMarketData(const MarketData& data) {
    shortWindowPrices.push_back(data.price);
    if (shortWindowPrices.size() > shortWindowSize) shortWindowPrices.pop_front();

    longWindowPrices.push_back(data.price);
    if (longWindowPrices.size() > longWindowSize) longWindowPrices.pop_front();

    if (shortWindowPrices.size() == shortWindowSize && longWindowPrices.size() == longWindowSize) {
        evaluateStrategy(data.price);
    }
}

void StrategyEngine::evaluateStrategy(double price) {
    double shortMA = 0, longMA = 0;

    for (double p : shortWindowPrices) shortMA += p;
    for (double p : longWindowPrices) longMA += p;

    shortMA /= shortWindowPrices.size();
    longMA /= longWindowPrices.size();

    if (shortMA > longMA && !positionOpen) {
        Order buyOrder{"AAPL", OrderType::BUY, price, 10};
        orderManager.placeOrder(buyOrder);
        positionOpen = true;
    } else if (shortMA < longMA && positionOpen) {
        Order sellOrder{"AAPL", OrderType::SELL, price, 10};
        orderManager.placeOrder(sellOrder);
        positionOpen = false;
    }
}
