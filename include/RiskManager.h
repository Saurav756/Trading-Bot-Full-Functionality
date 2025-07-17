#pragma once
#include "OrderManager.h"

class RiskManager {
public:
    RiskManager(double maxExposure);

    bool checkRisk(const Order& order, double currentExposure);
    double getMaxExposure() const;

private:
    double maxAllowedExposure;
};
