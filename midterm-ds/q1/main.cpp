#include "Node.h"
#include "Stack.h"
#include "List.h"

#include <iostream>
using namespace std;

Node* reverseList(Node *head);

int main() {
  List l;
  for(int i=1;i<=10;i++) 
    l.insert(i);
  cout<<"Original List: ";
  Node *temp=l.head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  l.head=reverseList(l.head);
  cout<<"\nReversed List: ";
  temp=l.head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

Node* reverseList(Node *head){
  //count nodes
  int count=0;
  Node *temp=head;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  Stack s(count);
  //push nodes on stack
  temp=head;
  while(temp!=NULL){
    s.push(temp);
    temp=temp->next;
  }
  List rev;
  while(!s.isEmpty()){
    rev.insert(s.pop()->data);
  }
  return rev.head;
}