#include "../include/OrderManager.h"
#include <iostream>

void OrderManager::placeOrder(const Order& order) {
    orderHistory.push_back(order);
    std::string side = (order.type == OrderType::BUY) ? "BUY" : "SELL";
    std::cout << "Order Placed: " << side << " " << order.symbol
              << " Qty: " << order.quantity << " Price: " << order.price << '\n';
}

const std::vector<Order>& OrderManager::getOrderHistory() const {
    return orderHistory;
}
