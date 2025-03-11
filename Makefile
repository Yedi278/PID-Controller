CXX=g++
CFLAGS=-Wall -g -std=c++11
# CFLAGS+=-DNDEBUG # comment this line to enable debug mode
LDLIBS=

# COLORS
RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

default: clean main run plot_all

all: clean main run plot_all

main: main.o
	$(CXX) -o build/main -Iinclude $(CFLAGS) build/main.o

	@echo -n "${GREEN}Build complete! ${NC}\n\n"

main.o: main.cpp include/customPID.h
	$(CXX) -c main.cpp -Iinclude $(CFLAGS) -o build/main.o

run: build/main
	./build/main

plot: run
	gnuplot -p test.gnuplot

plot_all: run
	gnuplot --persist test_all.gnuplot

clean:
	@echo -n "${RED}Cleaning... ${NC}\n"
	rm -f build/main.o build/main
	@echo -n "${GREEN}Cleaned! ${NC}\n\n"