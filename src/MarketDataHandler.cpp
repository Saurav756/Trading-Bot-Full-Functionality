#pragma once

#include <string>
#include <vector>
#include <functional>
#include <utility>

// Structure to hold market data tick
struct MarketData {
    std::string symbol;
    double price;
    long long timestamp; // Epoch time in nanoseconds or milliseconds
};

// Market Data Handler class
class MarketDataHandler {
public:
    using MarketDataCallback = std::function<void(const MarketData&)>;

    // Subscribe to market data for a given symbol
    void subscribe(const std::string& symbol, MarketDataCallback cb);

    // Simulate live market data (for demo/testing)
    void simulateData();

    // Load historical data from CSV for backtesting
    void loadFromCSV(const std::string& filepath);

private:
    std::vector<std::pair<std::string, MarketDataCallback>> subscribers;
};
