#pragma once

#include <iostream>
#include <string>
using namespace std;

class CircQueue
{
public:
	string *Array;
	int front, rear;
	int size, count;
	CircQueue(int);
	bool isEmpty();
	bool isFull();
	void enqueue(string);
	string dequeue();
	string getFront();
};
