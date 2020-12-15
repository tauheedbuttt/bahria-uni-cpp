#include "Node.h"
#include "List.h"

#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;


Node* sort(Node*);
Node* flatten(Node*);
int main() {
  ifstream f("input.txt");
  //read N
  int N=0; f>>N;
  if(N<0||N>50){
    cout<<"[WARNING] Invalid number of heads\n";
    return -1;
  }
  //read Elements number
  int *Mi=new int[N]{0};
  for(int i=0;i<N;i++){
    f>>Mi[i];
    if(Mi[i]<0||Mi[i]>20){
      cout<<"[WARNING] Invalid number of Elements\n";
      return -1;
    }
  }
  //create Lists
  List *l=new List[N];
  for(int i=0;i<N;i++){
    //insert values
    l[i].read(f,Mi[i]);
  }
  //link lists
  for(int i=0;i<N;i++){
    if(i!=N-1&&!l[i].empty()) l[i].head->next=l[i+1].head;
  }
  //display Lists
  cout<<"Before Flatten:\n"<<l;
  cout<<"After Flatten:\n"<<flatten(l->head)<<endl;
  cout<<"After Sort:\n"<<sort(flatten(l->head));
}

Node* flatten(Node* head){
  Node *temp1=head;
  Node *temp2=head->next;
  while(temp1!=NULL){
    temp1->next=NULL;
    while(temp1->bottom!=NULL) temp1=temp1->bottom;
    temp1->bottom=temp2;
    temp1=temp2;
    if(temp2!=NULL) temp2=temp2->next;
  }
  return head;
}
Node* sort(Node* head){
  int temp;
  Node *i=head;
  while(i!=NULL){
    Node *j=head;
    while(j!=NULL){
      if(i->data<j->data){
        temp=j->data;
        j->data=i->data;
        i->data=temp;
      }
      j=j->bottom;
    }
    i=i->bottom;
  }
  return head;
}