#pragma once
#include <iostream>
#define CAPACITY 10
class Stack
{
private:
	char data[CAPACITY];
	int ptr = 0;
public:
	int push(char p);
	int size();
	std::pair <char, int> pop();
	void printStack();
};
