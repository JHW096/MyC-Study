#include<iostream>
#include<string>
#define max 101
using namespace std;

template<class T>
class stack {
	T* data;
	int tos;

public:

	stack() {
		data = new T[max];
		tos = -1;
	}
	~stack() {
		cout << "delete data.." << endl;
		delete[] data;
	}

	bool empty() {
		if (tos == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if (tos == max - 1) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(T item) {
		if (isFull()) {
			cout << "Stack is Full.." << endl;
		}
		else {
			data[++tos] = item;
		}
	}

	T pop() {
		if (empty()) {
			cout << "stack is Empty.." << endl;
		}
		else {
			return data[tos--];
		}
	}

	T top() {
		if (empty()) {
			cout << "stack is Empty.." << endl;
		}
		else {
			return data[tos];
		}
	}

	T first() {
		if (empty()) {
			cout << "stack is Empty.." << endl;
		}
		else {
			return data[0];
		}
	}
	
	int size() {
		return this->tos + 1;
	}

};


int main(void) {

	stack<string> s;
	string insert;
	
	for (int i = 0; i < 3; i++) {
		cout << "insert : ";
		getline(cin, insert);
		s.push(insert);
	}

	cout << "Data size = " << s.size() << endl;
	
	for (int i = 0; i < 3; i++) {
		cout << s.pop() << endl;
	}

}
