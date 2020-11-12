#include "Node.h"
#include "List.h"

#include <iostream>
using namespace std;

Node* common(Node*,Node*);
int main() {
  List course1, course2, Common;
  string names[10]={"saad","ali","ahmed","ahsan","saeed","mehwish","sadia","parkash","mehdi","sehrosh"};
  for(int i=0;i<5;i++){
    course1.insert(names[i]);
    course2.insert(names[i+3]);
  }
  cout<<"Course 1: ";
  course1.traverse();
  cout<<endl;
  cout<<"Course 2: ";
  course2.traverse();
  cout<<endl;
  cout<<"Common Students: ";
  Common.head = common(course1.head,course2.head);
  Common.traverse();
}
Node* common(Node* a,Node* b){
  List temp;
  Node *i=a;
  while(i!=NULL){
    Node *j=b;
    while(j!=NULL){
      if(i->data==j->data)
      temp.insert(i->data);
      j=j->next;
    }
    i=i->next;
  }
  return temp.head;
}