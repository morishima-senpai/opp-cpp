CXX = g++
CXXFLAGS = -std=c++11 -I.

all: program

program: main.o Tree/Tree.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp Tree/Tree.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Tree/Tree.o: Tree/Tree.cpp Tree/Tree.h
	$(CXX) $(CXXFLAGS) -c Tree/Tree.cpp -o Tree/Tree.o

clean:
	rm -f program main.o Tree/Tree.o