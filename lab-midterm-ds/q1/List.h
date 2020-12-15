#pragma once
#include "Node.h"

#include <fstream>
#include <iostream>
using namespace std;

typedef int type;
class List{
  public:
  Node *head, *rear;
  List(){head=rear=NULL;}
  bool empty();
  void insert(type);
  void read(ifstream &, int);
  friend ostream& operator<<(ostream&, List *);
};