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

void vps(string insert) {

	char token;

	stack<char> stack;

	string left;
	string right;

	for (int i = 0; i < insert.length(); i++) {
		token = insert[i];

		stack.push(token);
	}

	while (!stack.empty()) {
		
		if (stack.top() == '(') {
			left.push_back(stack.pop());
		}
		else if (stack.top() == ')') {
			right.push_back(stack.pop());
		}
		else {
			stack.pop();
		}
	}
	if (left.length() == right.length()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}



int main(void) {

	int k = 0;

	string insert;
	
	do {
		cout << "insert : ";
		getline(cin, insert);
		vps(insert);
		k++;
	} while (k = 5);
}