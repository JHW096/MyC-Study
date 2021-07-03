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

int pri(char token) {
	switch (token) {
	case'+': case'-': return 1;
	case'*': case'/': return 2;
	}
	return -1;
}


string infix_to_postfix(string exp) {

	stack<char> stack;
	
	char token;

	string postfix;

	for (int i = 0; i < exp.length(); i++) {

		token = exp[i];

		switch (token) {
		case'+': case'-': case'*': case'/':
			while (!stack.empty() && (pri(stack.top()) >= pri(token))) {
				postfix.push_back(stack.pop());
			}
			stack.push(token);
			break;

		case '(':
			stack.push(token);
			break;

		case')':
			while (stack.top() != '(') {
				postfix.push_back(stack.pop());
			}
			if (stack.top() == '(') {
				stack.pop();
			}
			break;

		default:
			postfix.push_back(token);
			break;
		}

	}
	while (!stack.empty()) {
		postfix.push_back(stack.pop());
	}


	return postfix;

}

int eval(string postfix) {

	string exp2 = infix_to_postfix(postfix);

	stack<char> stack;
	int op1, op2;
	int value;

	char token;

	for (int i = 0; i < exp2.length(); i++) {
		token = exp2[i];

		if (token != '+' && token != '-' && token != '*' && token != '/') {
			value = token - 48;
			stack.push(value);
		}
		else {
			op2 = stack.pop();
			op1 = stack.pop();
			switch (token) {
			case'+': stack.push(op1 + op2); break;
			case'-': stack.push(op1 - op2); break;
			case'*': stack.push(op1 * op2); break;
			case'/': stack.push(op1 / op2); break;
			}
		}
	}


	return stack.pop();
}




int main(void) {

	string exp = "2*3-((4+5)*2)-4+2*5";
	
	cout << infix_to_postfix(exp) << endl;
	cout << eval(exp) << endl;
}