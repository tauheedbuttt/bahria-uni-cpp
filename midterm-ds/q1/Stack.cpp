#include "Stack.h"
#include "Node.h"

#include <iostream>
using namespace std;


Stack::Stack(int a){
    size=a;
    Array=new Node*[size]; 
    top=size;
}
void Stack::push(Node *a){
  Array[--top]=a;
}
Node* Stack::pop(){
  Node* result;
  if(isEmpty()) cout<<"Underflow!";
  else{
    result=Array[top];
    Array[top++]=NULL;
  }
  return result;
}
bool Stack::isEmpty()
{return (top==size);}
