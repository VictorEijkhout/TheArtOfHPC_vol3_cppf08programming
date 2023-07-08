/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** binary.cxx : binary tree
 ****
 ****************************************************************/

#include <algorithm>
using std::max;

#include <iostream>
using std::cin;
using std::cout;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <vector>
using std::vector;

//codesnippet treenode
class Node {
private:
  int key{0},count{0};
  shared_ptr<Node> left,right;
  bool hasleft{false},hasright{false};
public:
  Node() {}
  Node(int i,int init=1 ) { key = i; count = 1; };
  void addleft( int value) {
    left = make_shared<Node>(value);
    hasleft = true;
  };
  void addright( int value ) {
    right = make_shared<Node>(value);
    hasright = true;
  };
  //codesnippet end
  //codesnippet treeinsert
  void insert(int value) {
    if (key==value)
      count ++;
    else if (value<key) {
      if (hasleft)
	left->insert(value);
      else
	addleft(value);
    } else if (value>key) {
      if (hasright)
	right->insert(value);
      else
	addright(value);
    } else throw(1); // should not happen
  };
  //codesnippet end
  //codesnippet treecount
  int number_of_nodes() {
    int count = 1;
    if (hasleft)
      count += left->number_of_nodes();
    if (hasright)
      count += right->number_of_nodes();
    return count;
  };
  //codesnippet end
  //codesnippet treedepth
  int depth() {
    int d = 1, dl=0,dr=0;
    if (hasleft)
      dl = left->depth();
    if (hasright)
      dr = right->depth();
    d = max(d+dl,d+dr);
    return d;
  };
  //codesnippet end
  //codesnippet treenode
};
//codesnippet end

int main() {

  Node tree;
  tree.insert(5);
  tree.insert(-1);

  cout << "After two inserts, tree has " << tree.number_of_nodes() << " nodes" << '\n';

  tree.insert(1);
  tree.insert(7);

  cout << "After two more inserts, tree has " << tree.number_of_nodes() << " nodes," <<
    " and depth of " << tree.depth() << '\n';

  return 0;
}
