#include<iostream>
#include<string>
using namespace std;

int main(void) {

	string* name = new string("Take This sinking boat and point it home");
	name->append("We've still got time");
	name->append("Raise your hopeful voice you had a choice");
	name->append("You make it now");
	int* small = new int[26];
	int* large = new int[26]; 

	for (int i = 0; i < 26; i++) {
		small[i] = 0;
		large[i] = 0;
	}

	for (int i = 0; i < name->length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (name->at(i) == 'a' + j) {
				small[j]++;
			}
			if (name->at(i) == 'A' + j) {
				large[j]++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << char('a' + i) << "=" << small[i] << "°³ "
			<< char('A' + i) << "=" << large[i] << "°³" 
			<< "," << char('a' + i) << "+" << char('A' + i) << "="
			<< small[i] + large[i] << "°³" << endl;
	}

	delete name;
	delete[] small;
	delete[] large;

}