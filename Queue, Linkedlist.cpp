#include<iostream>
#include<string>
using namespace std;

template<class T>
struct node {
	T data;
	struct node* link;
};

template<class T>
struct queuelist {
	node<T>* front;
	node<T>* rear;
	queuelist* qlink;
};

template<class T>
class control {
	queuelist<T>* head;
	int length = 0;
public:

	control() {
		head = nullptr;
	}

	void init_queue(int line) {
		queuelist<T>* Qnode = new queuelist<T>[line];


		for (int i = 0; i < line; i++) {
			(Qnode + i)->front = nullptr;
			(Qnode + i)->rear = nullptr;
			(Qnode + i)->qlink = nullptr;
			length++;
		}


		head = Qnode;
		for (int i = 0; i < line - 1; i++) {
			(Qnode + i)->qlink = (Qnode + i + 1);
		}

	}

	void enqueue(int pos, T item) {

		node<T>* new_node = new node<T>();
		if (new_node == nullptr) {
			cout << "Error : No memory.." << endl;
			exit(1);
		}
		queuelist<T>* f_Qnode = head;
		new_node->data = item;
		new_node->link = nullptr;

		for (int i = 0; i < pos; i++) {
			f_Qnode = f_Qnode->qlink;
		}
		if (f_Qnode->rear == nullptr) {
			f_Qnode->front = new_node;
			f_Qnode->rear = new_node;
		}
		else {
			f_Qnode->rear->link = new_node;
			f_Qnode->rear = new_node;
		}

	}

	void dequeue(int pos) {
		queuelist<T>* Qnode = head;

		for (int i = 0; i < pos; i++) {
			Qnode = Qnode->qlink;
		}

		node<T>* remove_node = Qnode->front;
		Qnode->front = Qnode->front->link;
		delete remove_node;
	}

	void show() {
		queuelist<T>* Qnode = head;
		node<T>* print_node;
		int k = 0;
		for (; Qnode != nullptr; Qnode = Qnode->qlink) {
			k++;
			cout << k << "번째 연결리스트 : ";
			print_node = Qnode->front;
			for (; print_node != nullptr; print_node = print_node->link) {
				cout << print_node->data << "->";
			}
			cout << "NULL" << endl;
		}
	}

};

int main(void) {

	control<int> list;
	int line;
	cout << "How many lines? : ";
	cin >> line;
	list.init_queue(line);
	cout << "make " << line << "lines" << endl;
	list.enqueue(0, 1);
	list.enqueue(0, 2);
	list.enqueue(0, 3);
	list.enqueue(1, 11);
	list.enqueue(1, 22);
	list.enqueue(1, 33);
	list.enqueue(2, 111);
	list.enqueue(2, 222);
	list.enqueue(2, 333);
	list.show();

}