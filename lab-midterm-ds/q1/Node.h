#pragma once

#include <iostream>
using namespace std;

typedef int type;
class Node{
  public:
  type data;
  Node *next;
  Node *bottom;
  Node(type data=0, Node *bottom=NULL, Node *next=NULL);
  friend ostream& operator<<(ostream& o, Node* n);
};
