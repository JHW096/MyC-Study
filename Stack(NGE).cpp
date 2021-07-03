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


void NGE(int k) {

	int sequence[100];
	int answer[100];
	stack<int> stack;


	for (int i = 0; i < k; i++) {
		cout << i + 1 << "번째 배열 입력 : ";
		cin >> sequence[i];
	}

	for (int i = k - 1; i >= 0; i--) {
		while (!stack.empty() && stack.top() <= sequence[i]) {
			stack.pop();
		}
		if (stack.empty()) {
			answer[i] = -1;
		}
		else {
			answer[i] = stack.top();
		}
		stack.push(sequence[i]);
	}

	for (int i = 0; i < k; i++) {
		cout << answer[i] << " ";
	}

}



int main(void) {

	int k;
	cout << "배열의 크기를 입력 : ";
	cin >> k;
	NGE(k);

	
}