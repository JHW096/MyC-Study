#include<iostream>
using namespace std;
#define max 50
 
class Graph {
private:
	int n;
	int adj_mat[max][max];
	int vis[max];

public:

	Graph() {
		this->n = 0;
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				this->adj_mat[i][j] = false;
			}
		}
		for (int i = 0; i < max; i++) {
			this->vis[i] = false;
		}
		
	}

	~Graph() {
		cout << "removed Graph Class.." << endl;
	}

	void insert_vertex(int v) {
		if ((this->n + 1) > max) {
			cout << "Error, insert_vertex" << endl;
			exit(1);
		}
		this->n = v;
	}

	void insert_edge(int start, int end) {
		if (start >= this->n || end >= this->n) {
			cout << "Error, insert_edge" << endl;
			exit(1);
		}
		this->adj_mat[start][end] = true;
		this->adj_mat[end][start] = true;

	}
	
	void DFS(int v) {
		int w;
		this->vis[v] = true;
		cout << "Edge : " << v << " -> ";
		for (w = 0; w < this->n; w++) {
			if (this->adj_mat[v][w] && !vis[w]) {
				DFS(w);
			}
		}
	}

};


int main(void) {

	Graph* myG = new Graph();
	myG->insert_vertex(4);
	myG->insert_edge(0, 1);
	myG->insert_edge(0, 3);
	myG->insert_edge(1, 2);
	myG->insert_edge(2, 3);
	myG->DFS(0);
	cout << "Nullptr" << endl;

	delete myG;

}