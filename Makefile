#!make -f

demo: TreeDemo.o Tree.o
	clang++-6.0 -std=c++17 $^ -o demo

test: TreeTest.o Tree.o
	clang++-6.0 -std=c++17 $^ -o testT

%.o: %.cpp
	clang++-6.0 -std=c++17 --compile $< -o $@

TreeTest.o: badkan.hpp Tree.hpp
	clang++-6.0 -std=c++17 $^ -c TreeTest.cpp

TreeDemo.o: Tree.hpp
	clang++-6.0 -std=c++17 $^ -c TreeDemo.cpp

clean:
	rm -f *.o demo test
