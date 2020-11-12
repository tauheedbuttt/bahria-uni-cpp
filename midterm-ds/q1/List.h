#pragma once
#include "Node.h"

#include <iostream>
using namespace std;

typedef int type;
class List
{	
  public:
    Node *head;
    List();
    void insert(type);
    bool isEmpty();
};
