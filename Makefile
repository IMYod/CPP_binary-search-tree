CXX=clang++-6.0
CXXFLAGS=-std=c++17 

all: 
	$(CXX) $(CXXFLAGS) *.cpp
	./a.out
