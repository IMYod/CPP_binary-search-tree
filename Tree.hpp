/*
* This is a header file for BST 
* This file is part of task in Cpp course
*
* @author Yoav and Elad
*/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

namespace ariel{

/*
* This class represnt a nodes of the tree
* each node have a 
* 1. Data
* 2. Pointer to his parent 
* 3. Pointer to his right son
* 4. Pointer to his left son.
*/
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

/*********Getters and Setters**********/

  void setParent(Node* p) {parent = p;}
  void setRight(Node* r) {right = r;}
  void setLeft(Node* l) {left = l;}
  void setData(int i) {data = i;}

  Node* getParent() const {return parent;}
  Node* getRight() const {return right;}
  Node* getLeft() const {return left;}
  int getData() const {return data;}

/* This functions returns true if the node is leaf*/

  bool isLeaf() const {return (right==0 && left==0);}
};

/* This is The BST class
* for more info go to the link below:
*https://en.wikipedia.org/wiki/Binary_search_tree
*/

class Tree {

    Node* _root = NULL;
    int _size=0;

  public:
    Node* find(int toFind, Node* localRoot);
    void insertLocal(Node* toInsert, Node* localRoot);

    void printTree(Node *localRoot, int level);

    void deleteNode(Node* ptr);
    ~Tree() { deleteNode(_root); } //destructor

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
