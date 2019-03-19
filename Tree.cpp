#include "Tree.hpp"

using namespace ariel;

    Node* Tree::find(int toFind, Node* localRoot){
      if (localRoot==0)
	return 0;
      if (toFind > localRoot->getData())
	return find(toFind, localRoot->getRight());
      else if (toFind < localRoot->getData())
	return find(toFind, localRoot->getLeft());
      return localRoot;
    }

    void Tree::insertLocal(Node* toInsert, Node* localRoot){
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
	  throw std::string("The number " + std::to_string(toInsert->getData()) + "already exists in the tree");
    }

    //based on: stackoverflow.com/questions/40582699
    void Tree::printTree(Node *localRoot, int level){
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

    void Tree::deleteNode(Node* ptr){
      if (ptr){
	deleteNode(ptr->getLeft());
	deleteNode(ptr->getRight());
	delete(ptr);
      }
    }

    Tree& Tree::insert(int i){
	Node *toInsert = new Node(i);
	if (_root==0){
	  _root = toInsert;
	  _size++;
	}
	else
	  insertLocal(toInsert, _root);
	return *this;
    }

    Tree& Tree::remove(int i){
	Node *toRemove = find(i, _root);
	if (toRemove == NULL) //The number "i" don't exist
	  throw std::string("The number " + std::to_string(i) + "don't exists in the tree");
	Node *parentOf = toRemove->getParent();

	if (toRemove->isLeaf()){ //the node to remove is leaf
	  if (parentOf != NULL){
	    if (parentOf->getRight() == toRemove) //remove right child
		parentOf->setRight(NULL);
	    else //remove left child
		parentOf->setLeft(NULL);
	  }
	  else
	    _root = NULL; //delete the single node
	}

	else if (toRemove->getRight()==NULL){ //no right child to the removed node
	  toRemove->getLeft()->setParent(parentOf);
	  if (parentOf != NULL){
	    if (parentOf->getRight() == toRemove) //remove right child
		parentOf->setRight(toRemove->getLeft());
	    else //remove left child
		parentOf->setLeft(toRemove->getLeft());
	  }
	  else{ //remove the root
	    _root = toRemove->getLeft(); 
	  }
	}

	else if (toRemove->getLeft()==NULL){ //no right child to the removed node
	  toRemove->getRight()->setParent(parentOf);
	  if (parentOf != NULL){
	    if (parentOf->getLeft() == toRemove) //remove right child
		parentOf->setLeft(toRemove->getRight());
	    else //remove left child
		parentOf->setRight(toRemove->getRight());
	  }
	  else { //remove the root
	    _root = toRemove->getRight(); 
	  }
	}

	else { //the removed node has 2 childs
	  Node *next = toRemove->getRight(); //find successor
	  while (next->getLeft()) //while exist left child
	    next = next->getLeft();
	  toRemove->setData(next->getData());

	  toRemove = next; //remove next
	  parentOf = toRemove->getParent();
	  Node *rightC = toRemove->getRight();
	    parentOf->setLeft(rightC);
	  if (rightC != NULL)
	    rightC->setParent(parentOf);
	}
	
	_size--;
	delete(toRemove);
	return *this;
    }

   int Tree::root() {
	if (_root==NULL)
	  throw std::string("The root is NULL");
	return _root->getData();
   }

  int Tree::parent(int i) {
	if (i==root())
	  throw; //exception!!!;
	Node *member = find(i, _root);
	if (member==0)
	  throw; //exception!!!;
	return (member->getParent())->getData();
  }

  int Tree::right(int i) {
	Node *member = find(i, _root);
	if (member==0)
	  throw; //exception!!!;
	Node *theRight = member->getRight();
	if (theRight==0)
	  throw; //exception!!!;
	return theRight->getData();
  }

  int Tree::left(int i) {
	Node *member = find(i, _root);
	if (member==0)
	  throw; //exception!!!;
	Node *theLeft = member->getLeft();
	if (theLeft==0)
	  throw; //exception!!!;
	return theLeft->getData();
  }

