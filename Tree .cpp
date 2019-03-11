#include "Tree.hpp"


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
		cout << "parent("<< i <<")=" << t.parent(i) << "\t";	
		cout << "left("<< i <<")=" << t.left(i) << "\t";	
		cout << "right("<< i <<")=" << t.right(i) << endl;	
//		std::cout << "contains " << i << endl;
	}
	else
		std::cout << "not contains " << i << endl;
	}



	cout << "size=" << t.size() << endl;
	cout << "root=" << t.root() << endl;
	

	return 0;
}
