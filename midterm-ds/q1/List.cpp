#include "List.h"
#include "Node.h"

#include <iostream>
using namespace std;

typedef int type;

List::List()
{head=NULL;}
void List::insert(type val)
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
bool List::isEmpty()
{return head==NULL;}
