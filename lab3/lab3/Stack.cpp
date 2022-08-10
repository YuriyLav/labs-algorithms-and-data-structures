#include "Stack.h"
using namespace std;

int Stack::push(char p)
{
	if (ptr == CAPACITY)
		return 1;
	data[ptr++] = p;
	return 0;
}

int Stack::size()
{
	return ptr;
}

pair <char, int> Stack::pop()
{
	pair <char, int> p;
	if (ptr == 0) {
		p.second = 1;
		return p;
	}
	p.first = data[--ptr];
	return p;
}

void Stack::printStack()
{
	if (ptr == 0) return;
	for (int i = 0; i < ptr; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}
