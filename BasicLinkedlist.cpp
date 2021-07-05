#include<iostream>
#include<string>
using namespace std;

template <class T>
struct Node {
public:
	T data;
	struct Node<T>* link = nullptr;
};

template<class T>
class List {
	Node<T>* head;
	Node<T>* tail;
	int size = 0;
public:

	List() : head(nullptr), tail(nullptr) {} //lamda;

	~List() { };

	void add(T item) {
		Node<T>* new_node = new Node<T>;

		if (new_node == nullptr) {
			cout << "DBA error..to add(T)" << endl;
		}

		new_node->data = item;
		new_node->link = nullptr;

		if (head == nullptr) {
			head = new_node;
			tail = new_node;
		}
		else {
			tail->link = new_node;
			tail = tail->link;
		}
		size++;
	}

	void add(int pos, T item) {

		if (pos < 0 || pos > size) {
			cout << "can not use pos in list.." << endl;
			exit(1);
		}

		Node<T>* new_node = new Node<T>;
		Node<T>* replace = head;

		if (new_node == nullptr) {
			cout << "DBA error..to add(int, T)" << endl;
		}
		new_node->data = item;

		if (pos == 0 && head == nullptr) {
			new_node->link = nullptr;
			head = new_node;
			tail = new_node;
		}
		else if (pos == 0 && head != nullptr) {
			new_node->link = head;
			head = new_node;
		}
		else {
			for (int i = 0; i < pos - 1; i++) {
				replace = replace->link;
			}

			new_node->link = replace->link;
			replace->link = new_node;
		}
		size++;
	}

	void remove(int pos) {

		if (head == nullptr || pos < 0 || pos > this->size - 1) {
			cout << "can not use pos in remove.." << endl;
			exit(1);
		}

		Node<T>* first = head;
		Node<T>* second = first;

		if (pos == 0) {
			head = head->link;
			delete first;
		}
		else {
			for (int i = 0; i < pos; i++) {
				second = first;
				first = first->link;
			}
			second->link = first->link;
			delete first;
		}
		size--;
	}

	bool contains(T item) {

		T search = head->data;

		if (head == nullptr) {
			cout << "has no data.." << endl;
		}
		else {
			while (head != nullptr) {
				if (head->data == item) {
					return true;
				}
				else {
					return false;
				}
				head = head->link;
			}
		}
	}

	T get(int pos) {

		if (head == nullptr || pos < 0 || pos > this->size - 1) {
			cout << "can not use pos in get.." << endl;
			exit(1);
		}
		Node<T>* result = head;

		if (pos == 0) {
			return head->data;
		}
		else {
			for (int i = 0; i < pos; i++) {
				result = result->link;
			}
			return result->data;
		}

	}

	int length() {
		return this->size;
	}

	void clear() {
		Node<T>* node = head;

		while (node != nullptr) {
			head = node->link;
			delete node;
			node = head;
		}
		delete head;
		size = 0;
	}

	bool empty() {
		if (head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void show() {
		Node<T>* p = head;
		if (p == nullptr) {
			cout << "Nullptr" << endl;
		}
		else {
			while (p != nullptr) {
				cout << p->data << " -> ";
				p = p->link;
			}
			cout << "Nullptr";
		}
	}

	void info() {
		void show();
		cout << endl;
		cout << length() << endl;
	}
};



int main(void) {
	List<int> list;
	
	int num;
	int insert;
	int remove;

	cout << "How many insert data in list? : ";
	cin >> num;
	for (int i = 0; i < num; i++) {
		cout << "insert : ";
		cin >> insert;
		list.add(insert);
	}
	list.show();
	cout << endl;
	
	cout << "which data remove in list? : ";
	cin >> remove;
	list.remove(remove);
	cout << endl;
	list.show();

	list.clear();
	list.show();

}
