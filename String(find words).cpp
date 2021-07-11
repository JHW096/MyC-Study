#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int find_include_A_N(string str) {

	int count = 0;

	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	stringstream ss(str);
	string stringBuffer;
	vector<string> storage;

	while (getline(ss, stringBuffer, ' ')) {
		storage.push_back(stringBuffer);
	}
	for (int i = 0; i < storage.size(); i++) {
		bool A = false;
		bool N = false;
		for (int j = 0; j < storage[i].length(); j++) {
			if (storage[i].at(j) == 'a') {
				A = true;
			}
			else if (storage[i].at(j) == 'n') {
				N = true;
			}
		}
		if (A && N) {
			count++;
		}
	}
	return count;
}

int main(void) {

	string str = "banana And actioN";
	
	cout << find_include_A_N(str) << endl;

}