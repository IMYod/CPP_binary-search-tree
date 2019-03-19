#pragma once
#include <iostream>
#include <iomanip>
#include <string>

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
  void setData(int i) {data = i;}

  Node* getParent() {return parent;}
  Node* getRight() {return right;}
  Node* getLeft() {return left;}
  int getData() {return data;}

  bool isLeaf() {return (right==0 && left==0);}
};

class Tree {

    Node* _root = 0;
    int _size=0;

  public:
    Node* find(int toFind, Node* localRoot);
    void insertLocal(Node* toInsert, Node* localRoot);

    void printTree(Node *localRoot, int level);

    void deleteNode(Node* ptr);
    ~Tree() { deleteNode(_root); }

    Tree& insert(int i);

    Tree& remove(int i);

    bool contains(int i){ return (find(i, _root)!=NULL); }

   int size() {	return _size;}
   int root();

   int parent(int i);
   int right(int i);
   int left(int i);
   void print(){ printTree(_root, 0); }

};
}
