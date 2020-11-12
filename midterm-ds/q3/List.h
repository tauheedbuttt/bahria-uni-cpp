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
    void insert_end(type);
    void insert_beg(type);
    void traverse();
    bool isEmpty();
};