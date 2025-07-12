#include "MarketDataHandler.h"
#include <iostream>
#include <thread>
#include <chrono>

void MarketDataHandler::subscribe(const std::string& symbol, MarketDataCallback cb) {
    subscribers.push_back({symbol, cb});
}

void MarketDataHandler::simulateData() {
    for (int i = 0; i < 100; i++) {
        for (auto& sub : subscribers) {
            MarketData data{sub.first, 100.0 + i, std::chrono::system_clock::now().time_since_epoch().count()};
            sub.second(data);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
