#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int testStack() {
	Stack stack;
	string expr;
	cout << "Введите арифметическое выражение:" << endl;
	getline(cin, expr);
	for (int i = 0; i < expr.length() + 1; i++)
	{
		if (expr.length() == 1 && expr[0] == ' ') return -1; //выход из программы
		if (expr[i] == '(') { //добавление в стек
			stack.push(expr[i]);
		}
		if (expr[i] == ')') { //удаление из стека

			if (stack.pop().second == 1) {
				return 1;
			}
		}
		/*stack.printStack();*/
	}
	if (stack.size() == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

double foo(int n) //an=(3/2)^n*n!
{
	double answer = 0;
	if (n == 1) return(2.0 / 3);
	answer = foo(n - 1) * n * 2.0 / 3; // рекурсивный вызов
	return(answer);
}

int main()
{
	setlocale(LC_ALL, "rus");

	//EX 3
	cout << "______EX3______" << endl;
	int result = -1;
	while (true) {
		result = testStack();
		if (result == 0) cout << "Верно!" << endl;
		if (result == 1) cout << "Неверно!" << endl;
		if (result == -1) {
			cout << "Конец!" << endl;
			break;
		}
	}

	//EX 4
	cout << endl<<"______EX4______" << endl;
	int n = 5;
	cout << "n = " << n << "; результат: " << foo(n) << endl;

	//EX 6
	cout << endl << "______EX6______" << endl;
	cout << "Введите n: ";
	cin >> n;
	double* mas = new double[n];
	for (int i = 1; i < n + 1; i++) {
		mas[i - 1] = foo(i);
		cout << "n = " << i << "; результат = " << foo(i) << endl;
	}
	return 0;
}