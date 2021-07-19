#include<iostream>
#define Max 100
using namespace std;

template<class T>
class Basicheap {
private:
	T key;
	T heap[Max];
	int length;
public:

	Basicheap() {
		this->length = 0;
	}

	~Basicheap() {
		cout << "Remove BasicHeap Class.." << endl;
	}
	
	void add(T item) {

		int i = ++(length);

		while ((i != 1) && (item > heap[i / 2])) {
			heap[i] = heap[i / 2];
			i = i / 2;
		}
		heap[i] = item;

	}

	void remove() {
		int parent, child;
		T temp = this->heap[(this->length)--];
		parent = 1;
		child = 2;

		while (child <= this->length) {
			if ((child <= this->length) && (this->heap[child] < this->heap[child + 1])) {
				child++;
			}
			if (temp >= this->heap[child]) break;

			this->heap[parent] = this->heap[child];
			parent = child;
			child = child * 2;
		}
		this->heap[parent] = temp;
	}
	
	int size() {
		return (this->length);
	}

	T get(int pos) {
		if (pos > this->length && pos <= 0) {
			cout << "Error : can not selete.." << endl;
		}
		else {
			return heap[pos];
		}
	}

	void print() {
		for (int i = 1; i < this->length+1; i++) {
			cout << heap[i] << " ";
		}
	}
};


int main(void) {

	Basicheap<int> my;
	my.add(9);
	my.add(8);
	my.add(7);
	my.add(6);
	my.add(10);
	my.remove();
	cout << endl;
	my.print();
	cout << endl;
	cout << "Heap size = " << my.size() << endl;

	int a = my.get(2);
	cout << "get array[2] =" << a << endl;

}