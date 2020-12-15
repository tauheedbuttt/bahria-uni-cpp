#pragma once

#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

class Stack{
  queue<int> q1,q2;
  public:
  Stack(){}
  bool empty();
  void push(int);
  int pop();
};
