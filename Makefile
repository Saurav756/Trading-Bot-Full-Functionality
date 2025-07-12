all: tradingbot

tradingbot: src/main.cpp src/MarketDataHandler.cpp
	g++ -std=c++17 -O2 src/main.cpp src/MarketDataHandler.cpp -Iinclude -o tradingbot

clean:
	rm -f tradingbot
