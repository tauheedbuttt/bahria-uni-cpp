#pragma once
#include "Node.h"

#include <iostream>
using namespace std;


class Stack
{	
  public:
    Node **Array;
    int top;
    int size;
    Stack(int);
    void push(Node*);
    Node* pop();
    bool isEmpty();
};
