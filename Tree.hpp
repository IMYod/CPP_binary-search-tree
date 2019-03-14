#include <iostream>
#include <iomanip>

namespace ariel{


class Node {
  private:	
    int data;
    Node *parent, *right, *left;

  public:
  Node(int i){
    data = i;
    parent = 0;
    right = 0;
    left = 0;
  }

  void setParent(Node* p) {parent = p;}
  void setRight(Node* r) {right = r;}
  void setLeft(Node* l) {left = l;}

  Node* getParent() {return parent;}
  Node* getRight() {return right;}
  Node* getLeft() {return left;}
  int getData() {return data;}

  bool isLeaf() {return (right==0 && left==0);}
};

class Tree {
  private:
    Node* _root = 0;
    int _size=0;

    Node* find(int toFind, Node* localRoot){
      if (localRoot==0)
	return 0;
      if (toFind > localRoot->getData())
	return find(toFind, localRoot->getRight());
      else if (toFind < localRoot->getData())
	return find(toFind, localRoot->getLeft());
      return localRoot;
    }

    void insertLocal(Node* toInsert, Node* localRoot){
	if (toInsert->getData() > localRoot->getData()){
	  if (localRoot->getRight() == 0){
	    _size++;
	    localRoot->setRight(toInsert);
	    toInsert->setParent(localRoot);
	  }
	  else
	    insertLocal(toInsert, localRoot->getRight());
	}
	else if (toInsert->getData() < localRoot->getData()){
	  if (localRoot->getLeft() == 0){
	    _size++;
	    localRoot->setLeft(toInsert);
	    toInsert->setParent(localRoot);
	  }
	  else
	    insertLocal(toInsert, localRoot->getLeft());
	}
	else
	  std::cout << "There is a duplication!" << std::endl;//change to: throw exception!!!
    }

    //based on: stackoverflow.com/questions/40582699
    void printTree(Node *localRoot, int level){
	if (localRoot != 0){
	  if (level)
	    std::cout << std::setw(4*level) << ' ';
	  std::cout << localRoot->getData() << std::endl;
	  if (localRoot->getLeft()){
	    std::cout << 'L';
	    printTree(localRoot->getLeft(), level+1);
	  }
	  if (localRoot->getRight()){
	    std::cout << 'R';
	    printTree(localRoot->getRight(), level+1);
	  }
	}
    }

    Node* findFollow(Node* localRoot){
	if (localRoot == NULL)
	  return 0;
	if (localRoot->getRight() == NULL) //not exist right chils
	  return 0;
	Node *nodePtr = localRoot->getRight();
	while (nodePtr->getLeft()){ //while exist left child
	  nodePtr = nodePtr->getLeft();
	}
	return nodePtr;
    }

  public:
    Tree& insert(int i){
	Node *toInsert = new Node(i);
	if (_root==0){
	  _root = toInsert;
	_size++;
	}
	else
	  insertLocal(toInsert, _root);
	return *this;
    }

    void remove(int i){
	Node *toRemove = find(i, _root);
	if (toRemove == 0) //The number "i" don't exist
	  return; //change to: throw exception!!!
	Node *parentOf = toRemove->getParent();

	if (toRemove->isLeaf()){ //the node to remove is leaf
	  if (parentOf != 0){
	    if (parentOf->getRight() == toRemove) //remove right child
		parentOf->setRight(0);
	    else //remove left child
		parentOf->setLeft(0);
	  }
	}

	else if (toRemove->getRight()==0){ //no right child to the removed node
	  if (parentOf != 0)
	    parentOf->setLeft(toRemove->getLeft());
	  toRemove->getLeft()->setParent(parentOf);
	}

	else{
	  Node *next = findFollow(toRemove);
	  
	}
    }

    bool contains(int i){
	return (find(i, _root)!=0);
    }

   int size() {	return _size;}
   int root() {
	if (_root==0)
	  std::cout << "The root is NULL" << std::endl;//change to: throw exception!!!
	return _root->getData();
   }

  int parent(int i) {
	if (i==root())
	  return 0; //exception!!!;
	Node *member = find(i, _root);
	if (member==0)
	  return 0; //exception!!!;
	return (member->getParent())->getData();
  }

  int right(int i) {
	Node *member = find(i, _root);
	if (member==0)
	  return 0; //exception!!!;
	Node *theRight = member->getRight();
	if (theRight==0)
	  return 0; //exception!!!;
	return theRight->getData();
  }

  int left(int i) {
	Node *member = find(i, _root);
	if (member==0)
	  return 0; //exception!!!;
	Node *theLeft = member->getLeft();
	if (theLeft==0)
	  return 0; //exception!!!;
	return theLeft->getData();
  }

  void print(){ printTree(_root, 0); }

};
}
