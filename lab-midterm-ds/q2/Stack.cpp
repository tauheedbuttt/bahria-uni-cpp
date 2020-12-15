#include "Stack.h"

#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

bool Stack::empty()
{return q1.empty()&&q2.empty();}

void Stack::push(int val){
  if(empty()) q1.push(val);
  else if(!q1.empty()) 
	q1.push(val);
  else if(!q2.empty()) 
	q2.push(val);
}

int Stack::pop(){
  if(empty()) return -1;
  int result=0;
  if(!q1.empty()){
    while(q1.size()>1){
      q2.push(q1.front());
      q1.pop();
    }
    result=q1.front(); q1.pop();
  }
  else if(!q2.empty()){
    while(q2.size()>1){
      q1.push(q2.front());
      q2.pop();
    }
    result=q2.front(); q2.pop();
  }
  return result;
}
