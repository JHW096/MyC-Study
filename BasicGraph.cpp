#include<iostream>
#define Max 100
using namespace std;

class Graph {
private:

	int n;
	int Matrix[Max][Max];

public:
	
	Graph() {
		this->n = 0;
		for (int i = 0; i < Max; i++) {
			for (int j = 0; j < Max; j++) {
				this->Matrix[i][j] = 0;
			}
		}
	}

	~Graph() {
		cout << "Removed Graph Class.." << endl;
	}

	void insert_vertics(int v) {
		if (this->n > Max) {
			cout << "Error : Vertics overflow.." << endl;
			exit(1);
		}
		this->n++;
	}

	void insert_edge(int start, int end) {
		if (start >= this->n || end >= this->n) {
			cout << "Error : Error : Can not use Edge number.." << endl;
			exit(1);
		}
		this->Matrix[start][end] = 1;
		this->Matrix[end][start] = 1;
	}

	void print() {
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->n; j++) {
				cout << this->Matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

};

int main(void) {

	Graph* myG = new Graph();
	for (int i = 0; i < 4; i++) {
		myG->insert_vertics(i);
	}
	myG->insert_edge(0, 1);
	myG->insert_edge(0, 2);
	myG->insert_edge(0, 3);
	myG->insert_edge(1, 2);
	myG->insert_edge(2, 3);
	myG->print();
	delete myG;

}