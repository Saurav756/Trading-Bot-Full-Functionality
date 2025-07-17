# Dockerfile
FROM ubuntu:20.04

# Install build tools
RUN apt-get update && apt-get install -y build-essential make git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# Build the trading bot
RUN make

# Run the trading bot by default
CMD ["./tradingbot"]
