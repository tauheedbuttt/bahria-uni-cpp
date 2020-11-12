#include "Queue.h"

#include <iostream>
using namespace std;

int main() {
 srand(time(NULL));
 CircQueue q(6);
 q.enqueue("Sarah");
 q.enqueue("Tim");
 q.enqueue("Zoe");
 q.enqueue("Miller");
 q.enqueue("Ana");
 q.enqueue("Brad");
 while(q.count<5){
  int time=rand()%20;
  for(int t=0 ; t<time ; t++){
      q.enqueue(q.dequeue());
  }
  cout<<"[INFO] Holder: "<<q.dequeue()<<endl;
  }
 cout<<"Winner is: "<<q.dequeue();
}