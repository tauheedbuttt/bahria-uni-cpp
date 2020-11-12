#include "Queue.h"

#include <string>
#include <iostream>
using namespace std;


CircQueue::CircQueue(int size)
{
  this->size=size;
  Array=new string[size];
  front=rear=0;
  count=size;
}
bool CircQueue::isFull(){return (count==0);}
bool CircQueue::isEmpty(){return (count==size);}
string CircQueue::getFront(){return Array[front];}
void CircQueue::enqueue(string value){
  if(isFull()) cout<<"Full!";
  else{
    Array[rear++]= value;
    rear = rear%size;            
    count--;
  }
}
string CircQueue::dequeue(){
  string result;
  if(isEmpty()) cout<<"Empty!";
  else{
    result=Array[front++];
    front=front%size;           
    count++;
  }
  return result;
}
