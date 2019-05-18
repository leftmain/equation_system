F = -std=c++11 -O3
all: a

a: main.cpp
	g++ $F main.cpp -o a

clean:
	rm a

