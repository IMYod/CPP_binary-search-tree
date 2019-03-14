#include "Tree.hpp"

using namespace ariel;

int main() {

	Tree t;
	
	t.insert(5);
	t.insert(4);
	t.insert(8);
	t.insert(6);
	t.insert(10);
	t.insert(7);
	t.insert(3);
	t.insert(1);
	t.insert(2);
	t.print();

	for (int i=1; i<12; i++){
	if (t.contains(i)){
		std::cout << "parent("<< i <<")=" << t.parent(i) << "\t";	
		std::cout << "left("<< i <<")=" << t.left(i) << "\t";	
		std::cout << "right("<< i <<")=" << t.right(i) << std::endl;	
//		std::cout << "contains " << i << endl;
	}
	else
		std::cout << "not contains " << i << std::endl;
	}



	std::cout << "size=" << t.size() << std::endl;
	std::cout << "root=" << t.root() << std::endl;
	

	return 0;
}
