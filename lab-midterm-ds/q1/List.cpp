#include "Node.h"
#include "List.h"

#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

bool List::empty(){return ((head==NULL)&&(rear==NULL));}
void List::insert(type val){
  Node *temp=new Node(val);
  if(empty()) head=rear=temp;
  else {rear->bottom=temp; rear=temp;}
}
void List::read(ifstream &f, int Mi){
  for(int i=0;i<Mi;i++){
    int val=0; f>>val;
    if(val<0||val>pow(10,3)){
      cout<<"[WARNING] Invalid number of Element\n";
      return;
    }
    insert(val);
  }
}
ostream& operator<<(ostream& o, List *l){
  Node *head=l->head;
  while(head!=NULL){
    cout<<head<<endl;
    head=head->next;
  }
  return o;
}