#include<iostream>
#include<string>
using namespace std;


template<class T>
class stack {
	T data[100];
	int tos;
public:

	stack() {
		this->tos = -1;
	}

	int empty() {
		return this->tos == -1;
	}

	int full() {
		return this->tos == 99;
	}

	void push(T item) {
		if (tos >= 99) {
			cout << "Error : Stack is Overflow.." << endl;
		}
		else {
			this->data[++tos] = item;
		}
	}

	T pop() {
		if (empty()) {
			cout << "Error : Stack is Empty.." << endl;
		}
		else {
			return this->data[tos--];
		}
	}

	T top() {
		if (empty()) {
			cout << "Error : Stack is Empty.." << endl;
		}
		else {
			return this->data[tos];
		}
	}

	int size() {
		return (this->tos + 1);
	}

};

int main(void) {

	stack<string> mystack;
	mystack.push("Woo");
	mystack.push("Hyeon");
	mystack.push("Jeon");

	cout << "stack내 원소의 갯수 = " << mystack.size() << endl;

	while (!mystack.empty()) {
		cout << mystack.pop() << endl;
	}

}