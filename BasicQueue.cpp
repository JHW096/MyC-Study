#include<iostream>
#include<string>
#define max 101
using namespace std;

template<class T>
class Queue {
	int rear;
	int front;
	int length;
	T* data;

public:

	Queue() {
		front = 0;
		rear = 0;
		length = 0;
		data = new T[max];
	}

	~Queue() {
		delete[] data;
	}

	bool empty() {
		if (front == rear) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if (rear == max - 1) {
			return true;
		}
		else {
			return false;
		}
	}

	void enqueue(T item) {
		if (isFull()) {
			cout << "Queue is Full.." << endl;
		}
		else {
			rear = (rear + 1) % max;
			data[rear] = item;
		}
	}

	T dequeue() {
		if (empty()) {
			cout << "Queue is empty.." << endl;
		}
		else {
			front = (front + 1) % max;
			return data[front];
		}
	}

	T top() {
		if (empty()) {
			cout << "Queue is empty.." << endl;
		}
		else {
			return data[(front + 1) % max];
		}
	}

	T end() {
		if (empty()) {
			cout << "Queue is empty.." << endl;
		}
		else {
			return data[rear];
		}
	}

	int size() {
		return rear - front;
	}

};


int main(void) {

	Queue<int> Q;
	int num;
	int insert;
	cout << "insert's num : ";
	cin >> num;
	for (int i = 0; i < num; i++) {
		cout << "insert : ";
		cin >> insert;
		Q.enqueue(insert);
	}

	cout << "Q.size = " << Q.size() << endl;
	cout << "dequeue result = ";
	for (int i = 0; i < num; i++) {
		cout << Q.dequeue() << " ";
	}
	
}