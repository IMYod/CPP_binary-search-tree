/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;

#include "Tree.hpp"
#include "badkan.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree; 
  ariel::Tree rightTree;
  ariel::Tree atbashTree;

  threetree.insert(5).insert(3).insert(7);
  rightTree.insert(1).insert(2).insert(3).insert(4).insert(5);
  atbashTree.insert(1).insert(7).insert(2).insert(6).insert(3).insert(5).insert(4);
  
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
  
  .CHECK_EQUAL (rightTree.size(), 5)
  .CHECK_EQUAL (rightTree.root(), 1)
  .CHECK_EQUAL (rightTree.right(3), 4)
  .CHECK_EQUAL (rightTree.parent(3), 2)
  .CHECK_EQUAL (rightTree.contains(5), true)
  .CHECK_EQUAL (rightTree.right(5), 0)
  .CHECK_OK (rightTree.remove(3))
  .CHECK_EQUAL (rightTree.right(2), 4)
  .CHECK_OK (rightTree.remove(4))
  .CHECK_THROWS(rightTree.remove(4))
  .CHECK_EQUAL (rightTree.contains(4), false)
  .CHECK_EQUAL (rightTree.right(2), 5)
  .CHECK_OK (rightTree.remove(5))
  .CHECK_EQUAL (rightTree.right(2), 0)
  .CHECK_OK (rightTree.remove(2))
  .CHECK_OK (rightTree.remove(1))
  .CHECK_EQUAL (rightTree.size(), 0)
  .CHECK_THROWS(rightTree.contains(1))
  .CHECK_OK    (rightTree.print())
  
  .CHECK_OK (atbashTree.remove(1))
  .CHECK_THROWS(atbashTree.contains(1))
  .CHECK_EQUAL(atbashTree.parent(2), 7)
  .CHECK_EQUAL(atbashTree.right(2), 6)
  .CHECK_EQUAL(atbashTree.right(2), 0)
  .CHECK_OK (atbashTree.remove(7))
  .CHECK_THROWS(atbashTree.contains(7))
  .CHECK_EQUAL(atbashTree.right(2), 6)
  .CHECK_OK (atbashTree.remove(5))
  .CHECK_EQUAL(atbashTree.parent(3), 6)
  .CHECK_OK (atbashTree.remove(4))
  .CHECK_OK (atbashTree.remove(3))
  .CHECK_OK (atbashTree.remove(6))  
  .CHECK_OK (atbashTree.remove(2))
  .CHECK_THROWS(atbashTree.contains(4))
  .CHECK_THROWS(atbashTree.contains(3))
  .CHECK_THROWS(atbashTree.contains(6))
  .CHECK_THROWS(atbashTree.contains(2))
  .CHECK_EQUAL (atbashTree.size(), 0)
  .CHECK_OK (atbashTree.insert(100))
  .CHECK_EQUAL (atbashTree.size(), 1)
  .CHECK_EQUAL(atbashTree.right(100), 0)
  .CHECK_EQUAL(atbashTree.left(100), 0)
  .CHECK_EQUAL(atbashTree.parent(100), 0)
  .CHECK_OK(atbashTree.print())

  





  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
