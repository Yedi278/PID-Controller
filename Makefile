CXX=g++


main: main.o
	$(CXX) -o build/main build/main.o

main.o: main.cpp
	$(CXX) -c main.cpp -o build/main.o

run: build/main
	./build/main 0.1 0.1 0.1 1000

plot: run
	gnuplot -p build/p.gnuplot