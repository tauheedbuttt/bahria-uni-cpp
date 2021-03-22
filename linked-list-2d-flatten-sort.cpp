#include <iostream>
#include <fstream>
using namespace std;

class Node{
  public:
  int data;
  Node *next=NULL;
  Node *bottom=NULL;
};

class List{
  public:
  int N;
  Node **head;
  int *Mi;
  List(int size, int *Mi){
    this->Mi=Mi;
    N=size;
    head=new Node*[size];
  }
  void insert(int i, int data){
    Node *node=new Node;
    node->data=data;
    if(head[i]==NULL) head[i]=node;
    else{
      Node *temp=head[i];
      while(temp->bottom!=NULL){
        temp=temp->bottom;
      }
      temp->bottom=node;
    }
  }
  void read(ifstream &f){
    for(int i=0;i<N;i++){
      for(int j=0;j<Mi[i];j++){
        int data=0; f>>data;
        insert(i,data);
      }
      if(i>0&&head[i-1]!=NULL){
        head[i-1]->next=head[i];
      }
    }
  }
  void traverse(){
    Node *h=head[0];
    while(h!=NULL){
      Node *temp=h;
      while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->bottom;
      }
      cout<<endl;
      h=h->next;
    }
  }
};

Node* flatten(Node* head){
  Node *temp1=head;
  Node *temp2=head->next;
  while(temp1!=NULL){
    temp1->next=NULL;
    while(temp1->bottom!=NULL)
      temp1=temp1->bottom;
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
int main() {
  ifstream f("input.txt");
  int N=0;
  f>>N;
  int *Mi=new int[N];
  for(int i=0;i<N;i++){
    f>>Mi[i];
  }
  List l(N,Mi);
  l.read(f);
  l.head[0]=sort(flatten(l.head[0]));
  l.traverse();
}
