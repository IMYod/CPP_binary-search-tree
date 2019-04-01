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
  ariel::Tree fullTree;

  threetree.insert(5).insert(3).insert(7);
  rightTree.insert(1).insert(2).insert(3).insert(4).insert(5);
  atbashTree.insert(1).insert(7).insert(2).insert(6).insert(3).insert(5).insert(4);
  fullTree.insert(20).insert(10).insert(30).insert(5).insert(15).insert(25).insert(40).insert(1).insert(6).insert(11).insert(16).insert(21).insert(26).insert(31).insert(46);  
  
  badkan::TestCase tc("Binary tree");
  
  /* Empty tree test */
  tc.CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  /* Three tree tests*/
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
  
  /* Right tree tests*/
  .CHECK_EQUAL (rightTree.size(), 5)
  .CHECK_EQUAL (rightTree.root(), 1)
  .CHECK_EQUAL (rightTree.right(3), 4)
  .CHECK_EQUAL (rightTree.parent(3), 2)
  .CHECK_EQUAL (rightTree.contains(5), true)
  .CHECK_THROWS(rightTree.right(5))
  .CHECK_OK (rightTree.remove(3))
  .CHECK_EQUAL (rightTree.right(2), 4)
  .CHECK_OK (rightTree.remove(4))
  .CHECK_THROWS(rightTree.remove(4))
  .CHECK_EQUAL (rightTree.contains(4), false)
  .CHECK_EQUAL (rightTree.right(2), 5)
  .CHECK_OK (rightTree.remove(5))
  .CHECK_THROWS(rightTree.right(2))
  .CHECK_OK (rightTree.remove(2))
  .CHECK_OK (rightTree.remove(1))
  .CHECK_EQUAL (rightTree.size(), 0)
  .CHECK_THROWS(rightTree.contains(1))
  .CHECK_OK    (rightTree.print())

  /* Atbash tree tests*/
  .CHECK_OK (atbashTree.remove(1))
  .CHECK_THROWS(atbashTree.remove(1))
  .CHECK_EQUAL (atbashTree.parent(2), 7)
  .CHECK_EQUAL (atbashTree.right(2), 6)
  .CHECK_THROWS(atbashTree.right(2))
  .CHECK_OK (atbashTree.remove(7))
  .CHECK_THROWS(atbashTree.remove(7))
  .CHECK_EQUAL (atbashTree.right(2), 6)
  .CHECK_OK (atbashTree.remove(5))
  .CHECK_EQUAL (atbashTree.parent(3), 6)
  .CHECK_OK (atbashTree.remove(4))
  .CHECK_OK (atbashTree.remove(3))
  .CHECK_OK (atbashTree.remove(6))  
  .CHECK_OK (atbashTree.remove(2))
  .CHECK_THROWS(atbashTree.remove(4))
  .CHECK_THROWS(atbashTree.remove(3))
  .CHECK_THROWS(atbashTree.remove(6))  
  .CHECK_THROWS(atbashTree.remove(2))
  .CHECK_EQUAL (atbashTree.contains(4), false)
  .CHECK_EQUAL (atbashTree.contains(3), false)
  .CHECK_EQUAL (atbashTree.contains(6), false)  
  .CHECK_EQUAL (atbashTree.contains(2), false)
  .CHECK_EQUAL (atbashTree.size(), 0)
  .CHECK_OK (atbashTree.insert(100))
  .CHECK_EQUAL (atbashTree.size(), 1)
  .CHECK_THROWS(atbashTree.right(100))
  .CHECK_THROWS(atbashTree.left(100))
  .CHECK_THROWS(atbashTree.parent(100))
  .CHECK_OK (atbashTree.print())

  /* Full tree tests*/
  .CHECK_EQUAL (fullTree.size(), 15) 
  .CHECK_EQUAL (fullTree.root(), 20)
  .CHECK_OK (fullTree.remove(40)) /*remove node 40*/
  .CHECK_EQUAL (fullTree.parent(46), 31)
  .CHECK_EQUAL (fullTree.parent(31), 30)
  .CHECK_THROWS(fullTree.left(31))
  .CHECK_THROWS(fullTree.remove(40))
  .CHECK_EQUAL (fullTree.contains(10), false)  
  .CHECK_OK (fullTree.remove(10)) /* remove node 10*/
  .CHECK_EQUAL (fullTree.parent(5), 6)
  .CHECK_EQUAL (fullTree.parent(15), 6)
  .CHECK_EQUAL (fullTree.parent(1), 5)
  .CHECK_EQUAL (fullTree.right(5), 0) //
  .CHECK_THROWS(fullTree.remove(10))
  .CHECK_EQUAL (fullTree.contains(10), false)
  .CHECK_THROWS(fullTree.right(16))
  .CHECK_THROWS(fullTree.left(16))
  .CHECK_OK (fullTree.remove(20)) /*remove root*/ 
  .CHECK_EQUAL (fullTree.root(), 16)
  .CHECK_EQUAL (fullTree.right(16), 30)
  .CHECK_EQUAL (fullTree.left(16), 6)
  .CHECK_THROWS(fullTree.right(15))
  .CHECK_EQUAL (fullTree.left(15), 11)
  .CHECK_THROWS(fullTree.remove(20))
  .CHECK_EQUAL (fullTree.contains(10), false)
  .CHECK_OK (fullTree.insert(50)) /*insert a new node*/ 
  .CHECK_THROWS(fullTree.insert(50))
  .CHECK_EQUAL (fullTree.right(46), 50)
  .CHECK_THROWS(fullTree.left(46))
  .CHECK_EQUAL (fullTree.size(), 13)
  .CHECK_OK (fullTree.print()) /* print*/

  




  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
