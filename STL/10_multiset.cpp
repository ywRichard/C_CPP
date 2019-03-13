#include "stdafx.h"
#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset<int> set;//element value not unique
	int tmp = 0;

	do {
		cout << "input value:";
		cin >> tmp;
		if (tmp != 0)
			set.insert(tmp);
	} while (tmp != 0);

	for (multiset<int>::iterator it = set.begin(); it != set.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
