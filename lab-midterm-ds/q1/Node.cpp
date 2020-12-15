#include "Node.h"

#include <iostream>
using namespace std;

Node::Node(type data, Node *bottom, Node *next){
  this->data=data;
  this->next=next;
  this->bottom=bottom;
}
ostream& operator<<(ostream& o, Node* n){
  Node *temp=n;
  while(n!=NULL){
    cout<<n->data<<" ";
    n=n->bottom;
  }
  return o;
}