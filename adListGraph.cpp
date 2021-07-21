#include<iostream>
#define Max 50
using namespace std;

class Graph {
private:
	struct Node {
		int vertex;
		Node* link;
	};
	int n;
	Node* list[Max];

public:

	Graph() {
		this->n = 0; 
		for (int i = 0; i < Max; i++) {
			this->list[i] = nullptr;
		}
	}
	
	~Graph() {
		cout << "Removed Graph Class.." << endl;
	}

	void insert_vertex(int v) {
		if (this->n > Max) {
			cout << "Error.." << endl;
			exit(1);
		}
		this->n = v;
	}

	void insert_edge(int u, int v) {
		Node* node = new Node();
		node->vertex = v;
		node->link = this->list[u];
		this->list[u] = node;
	}

	void print() {
		for (int i = 0; i < this-> n; i++) {
			Node* p = this->list[i];
			cout << "list" << i << " : ";
			while (p != nullptr) {
				cout << "->" << p->vertex;
				p = p->link;
			}
			cout << endl;
		}
	}

};


int main(void) {

	Graph* myG = new Graph();
	myG->insert_vertex(4);
	myG->insert_edge(0, 1);
	myG->insert_edge(1, 0);
	myG->insert_edge(1, 2);
	myG->insert_edge(2, 1);
	myG->insert_edge(0, 2);
	myG->insert_edge(2, 0);
	myG->insert_edge(3, 2);
	myG->insert_edge(2, 3);
	myG->insert_edge(0, 3);
	myG->insert_edge(3, 0);
	myG->print();

	delete myG;

}