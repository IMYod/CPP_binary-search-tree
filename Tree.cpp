#include "Tree.hpp"

using namespace ariel;
 /*
 * 
 * 
 */
    Node* Tree::find(int toFind, Node* localRoot){
      if (localRoot==NULL)
	return NULL;
      if (toFind > localRoot->getData())
	return find(toFind, localRoot->getRight());
      else if (toFind < localRoot->getData())
	return find(toFind, localRoot->getLeft());
      return localRoot;
    }

    void Tree::insertLocal(Node* toInsert, Node* localRoot){
	if (toInsert->getData() > localRoot->getData()){
	  if (localRoot->getRight() == NULL){
	    _size++;
	    localRoot->setRight(toInsert);
	    toInsert->setParent(localRoot);
	  }
	  else
	    insertLocal(toInsert, localRoot->getRight());
	}
	else if (toInsert->getData() < localRoot->getData()){
	  if (localRoot->getLeft() == NULL){
	    _size++;
	    localRoot->setLeft(toInsert);
	    toInsert->setParent(localRoot);
	  }
	  else
	    insertLocal(toInsert, localRoot->getLeft());
	}
	else
	  throw std::string("The number " + std:: to_string(toInsert->getData()) + " already exists in the tree");
    }

    //based on: stackoverflow.com/questions/40582699
    void Tree::printTree(Node *localRoot, int level){
	if (localRoot != NULL){
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
	if (_root==NULL){
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
	  throw std::string("The number " + std:: to_string(i) + " doesn't exists in the tree");
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
	  bool the_next_is_right = (next->getLeft()==NULL);
	  while (next->getLeft()) //while exist left child
	    next = next->getLeft();
	  remove(next->getData()); //now we should remove next
	  toRemove->setData(next->getData());
	  _size++; //In the recursive function we already reduced the size
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
	  throw std::string("The number " + std:: to_string(i) + "have no parent");
	Node *member = find(i, _root);
	if (member==NULL)
	  throw std::string("The number " + std:: to_string(i) + "have no parent");
	return (member->getParent())->getData();
  }

  int Tree::right(int i) {
	Node *member = find(i, _root);
	if (member==NULL)
	  throw std::string("The number " + std:: to_string(i) + "have no right");
	Node *theRight = member->getRight();
	if (theRight==NULL)
	  throw std::string("The number " + std:: to_string(i) + "have no right");
	return theRight->getData();
  }

  int Tree::left(int i) {
	Node *member = find(i, _root);
	if (member==NULL)
	  throw std::string("The number " + std:: to_string(i) + "have no left");
	Node *theLeft = member->getLeft();
	if (theLeft==NULL)
	  throw std::string("The number " + std:: to_string(i) + "have no left");
	return theLeft->getData();
  }

