#pragma once
#include <string>
#include <vector>
#include <functional>

struct MarketData {
    std::string symbol;
    double price;
    long timestamp; // For simplicity, using epoch time
};

class MarketDataHandler {
public:
    using MarketDataCallback = std::function<void(const MarketData&)>;

    void subscribe(const std::string& symbol, MarketDataCallback cb);
    void simulateData();
    
private:
    std::vector<std::pair<std::string, MarketDataCallback>> subscribers;
};
