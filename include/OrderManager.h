#pragma once
#include <string>
#include <vector>

enum class OrderType { BUY, SELL };

struct Order {
    std::string symbol;
    OrderType type;
    double price;
    int quantity;
};

class OrderManager {
public:
    void placeOrder(const Order& order);
    const std::vector<Order>& getOrderHistory() const;

private:
    std::vector<Order> orderHistory;
};
