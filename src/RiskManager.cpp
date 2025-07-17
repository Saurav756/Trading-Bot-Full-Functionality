#include "../include/RiskManager.h"
#include <iostream>

RiskManager::RiskManager(double maxExposure) : maxAllowedExposure(maxExposure) {}

bool RiskManager::checkRisk(const Order& order, double currentExposure) {
    double orderValue = order.price * order.quantity;
    double newExposure = currentExposure;

    if (order.type == OrderType::BUY) {
        newExposure += orderValue;
    } else if (order.type == OrderType::SELL) {
        newExposure -= orderValue;
        if (newExposure < 0) newExposure = 0; // prevent negative exposure
    }

    if (newExposure > maxAllowedExposure) {
        std::cout << "Order Rejected: " 
                  << ((order.type == OrderType::BUY) ? "BUY" : "SELL")
                  << " " << order.symbol << " x" << order.quantity 
                  << " @ " << order.price 
                  << " (Exceeds Max Exposure: $" << maxAllowedExposure << ")\n";
        return false;
    }

    return true;
}

double RiskManager::getMaxExposure() const {
    return maxAllowedExposure;
}
