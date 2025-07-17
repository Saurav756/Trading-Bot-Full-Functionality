<<<<<<< HEAD
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


=======
# Trading Bot Full Functionality

A **high-performance**, **multi-threaded** trading bot written in **modern C++ (C++17)** for **stocks and futures**. This project showcases the core components of a production-grade trading system: real-time market data ingestion, order management, risk controls, strategy execution, backtesting, and concurrency for low-latency performance.

---

## Features

- **Modular Design**
  - **MarketDataHandler**: Simulates live market data or replays historical CSV data for backtesting.
  - **OrderManager**: Places, logs, and tracks orders with an internal order history.
  - **RiskManager**: Enforces exposure limits and rejects orders that exceed risk thresholds.
  - **StrategyEngine**: Implements a moving average crossover strategy with configurable short/long windows.
  - **Backtesting Engine**: Runs strategies against historical data to validate performance.
  - **Concurrency**: Separates data feed, strategy logic, and order execution into distinct threads for realistic, low-latency operation.

---

## Project Structure

```plaintext
Trading-Bot-Full-Functionality/
├── include/
│   ├── MarketDataHandler.h   # Market data interfaces
│   ├── OrderManager.h        # Order placement & tracking
│   ├── RiskManager.h         # Exposure and risk checks
│   └── StrategyEngine.h      # Trading logic (MA crossover)
├── src/
│   ├── MarketDataHandler.cpp
│   ├── OrderManager.cpp
│   ├── RiskManager.cpp
│   ├── StrategyEngine.cpp
│   └── main.cpp              # Entry point & orchestration
├── data/                     # Sample CSV data for backtesting
├── Makefile                  # Build automation
└── README.md                 # This document
```

---

## Prerequisites

- C++17-compatible compiler (GCC, Clang, MSVC)
- `make` or `cmake`
- [Optional] Python (for advanced analytics or plotting)

---

## Installation & Build

1. **Clone the repository**

   ```bash
   git clone https://github.com/Saurav756/Trading-Bot-Full-Functionality.git
   cd Trading-Bot-Full-Functionality
   ```

2. **Build with Make**

   ```bash
   make
   ```

3. **Clean build artifacts**

   ```bash
   make clean
   ```

---

## ▶Usage

### Live Simulation Mode

By default, the bot runs in live-simulation mode:

```bash
./tradingbot
```

- Spawns a **market data thread** that simulates price ticks.
- Feeds each tick to the **StrategyEngine**.
- Logs order placements and risk rejections to the console.

### Backtesting Mode

To replay historical data, modify `main.cpp`:

```cpp
// Replace live simulation
// mdh.simulateData();
// With CSV backtesting
mdh.loadFromCSV("data/data.csv");
```

Rebuild and run:

```bash
make && ./tradingbot
```

All CSV ticks are processed in sequence, and executed orders are logged for offline analysis.

---

## Configuration

- **Risk Limit**: Adjust the maximum exposure in `main.cpp` when constructing `RiskManager`.
- **Strategy Parameters**: Tweak `shortWindow` and `longWindow` in `StrategyEngine` to refine signal sensitivity.
- **Subscribed Symbols**: Add or remove symbols by calling `mdh.subscribe("SYMBOL", callback)` in `main.cpp`.

---

## Extending the Bot

- **Add New Strategies**: Create new strategy classes following the same callback pattern.
- **Live Market Integration**: Replace `simulateData()` with a real API connector (FIX, WebSocket).
- **Persistent Storage**: Integrate a database (SQLite, PostgreSQL) to archive trades and P&L.
- **Visualization**: Use ImGui + ImPlot for real-time dashboards, or export logs for Python-based plotting.

---

## Contributing

Contributions are welcome! Open issues or pull requests on GitHub to:

- Report bugs
- Propose new features
- Improve documentation

---

## License

Distributed under the **MIT License**. See [LICENSE](LICENSE) for details.
>>>>>>> Updating Readme
