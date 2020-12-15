#include "Stack.h"

#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream f("input.txt");
  Stack s;
  int Q=0; f>>Q;
  if(Q<0||Q>100){
    cout<<"[WARNING] Invalid number of Queries\n";
    return -1;
  }
  int x=0;
  for(int i=0;i<Q;i++){
    f>>x;
    if(x==1){
      //push
      f>>x;
      if(x<0||x>100){
        cout<<"[WARNING] Invalid number of Query\n";
        continue;
      }
      s.push(x);
    }
    else if(x==2){
      //pop
      cout<<s.pop()<<" ";
    }
    else{
      cout<<"[Warning] Invalid Query\n";
    }
  }
}
