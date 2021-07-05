#include<iostream>
#include<queue>
using namespace std;

void J_sequence(int k, int n) {
	queue<int> Q;
	int tmp;

	for (int i = 1; i <= n; i++) {
		Q.push(i);
	}
	while (!Q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		tmp = Q.front();
		cout << tmp << ", ";
		Q.pop();
	}

}

int main(void) {

	int k, n;
	cout << "< K, N > : ";
	cin >> k >> n;
	J_sequence(k, n);

}
