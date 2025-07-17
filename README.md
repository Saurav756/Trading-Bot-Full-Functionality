A high-performance, multi-threaded trading bot written in modern C++ (C++17), designed for stocks and futures markets. This project demonstrates key components of a production-grade trading system, including market data ingestion, order management, risk checks, strategy execution, multithreading, and backtesting support.

Features

Modular Architecture

MarketDataHandler: Simulates live market data or loads historical CSV data for backtesting.

OrderManager: Places, logs, and tracks orders.

RiskManager: Enforces exposure limits and rejects orders exceeding risk thresholds.

StrategyEngine: Implements a moving average crossover strategy with configurable short/long windows.
A high-performance, multi-threaded trading bot written in modern C++ (C++17), designed for stocks and futures markets. This project demonstrates key components of a production-grade trading system, including market data ingestion, order management, risk checks, strategy execution, multithreading, and backtesting support.

Backtesting Engine: Runs strategy on historical data via CSV files.

Multi-threading: Separates data feed simulation from strategy execution for realistic low-latency behavior.

Prerequisites

C++17 compatible compiler (GCC, Clang, MSVC)

Make or CMake

[Optional] Python (for advanced analytics or plotting backtest results)


