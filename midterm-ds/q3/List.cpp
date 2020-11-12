#include "List.h"
#include "Node.h"

#include <iostream>
using namespace std;

typedef int type;

List::List()
{head=NULL;}
void List::insert_end(type val)
{
  Node *newNode=new Node;
  newNode->data=val;
  newNode->next=NULL;
  if(isEmpty()) head=newNode;
  else{
    Node *temp=head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newNode;
  }  
}
void List::insert_beg(type val){
  Node *newNode=new Node;
  newNode->data=val;
  newNode->next=NULL;
  if(isEmpty()) head=newNode;
  else{
    newNode->next=head;
    head=newNode;
  }
}
void List::traverse(){
  Node *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
bool List::isEmpty()
{return head==NULL;}
