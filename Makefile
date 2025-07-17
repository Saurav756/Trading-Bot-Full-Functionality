all: tradingbot

tradingbot: src/main.cpp src/MarketDataHandler.cpp src/OrderManager.cpp src/StrategyEngine.cpp src/RiskManager.cpp
	g++ -std=c++17 -O2 $^ -Iinclude -o tradingbot

clean:
	rm -f tradingbot
