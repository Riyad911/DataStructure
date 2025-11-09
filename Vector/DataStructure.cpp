#include <iostream>
#include "Vector.h"
#include <string>

using namespace std;

int main()
{
	Vector<int> v, v1, v2, v3; // Size = 0,  Capacity = 0;
	cout << "\n************************************Q1************************************\n";
	cout << "\nThe Elements Of Vector: ";
	v.push_back(1);// Size = 1,  Capacity = 1;
	v.push_back(2);// Size = 2,  Capacity = 2;
	v.push_back(3);// Size = 3,  Capacity = 4;
	v.push_back(4);// Size = 4,  Capacity = 4;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\nThe Elements After Reverse: ";
	v.reverse();
	cout << endl;
	cout << "\n************************************Q2************************************\n";
	v1.push_back(6);
	v1.push_back(1);
	v1.push_back(8);
	v1.push_back(1);
	v1.push_back(9);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(6);
	cout << "\nThe Elements Of Vector: ";
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << "\nThe Elements After Delete Non-Nnique: ";
	v1.remove_non_unique();
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << "\n\n************************************Q3************************************\n";
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(7);
	cout << "\nThe Elements Of Vector: ";
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	v2.push_at(2, 99);
	cout << "\nThe Elements After put 99 at position 2: ";
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << "\n\n************************************Q4************************************\n";

	Vector<string> vs;
	vs.push_back("red");
	vs.push_back("green");
	vs.push_back("black");
	vs.push_back("white");
	vs.push_back("Pink");
	cout << "\nThe Elements Of Vector: ";
	for (int i = 0; i < vs.size(); i++) {
		cout << vs[i] << " ";
	}
	vs.capitaliz_first_letter();
	cout << "\nThe Elements After Capitalize The First Character: ";
	for (int i = 0; i < vs.size(); i++) {
		cout << vs[i] << " ";
	}
	cout << "\n\n************************************Q5************************************\n";
	v3.push_back(7);
	v3.push_back(5);
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(1);
	v3.push_back(5);
	v3.push_back(6);
	cout << "\nThe Elements Of Vector: ";
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";
	}
	cout << "\nThe Elements After Delete Smaller Than Adjacent Neighbors: ";
	v3.smaller_adijacent();
	cout << "\n\n\n\n\n\n";

	return 0;
}


/*Vector<int>::iterator itr;
for (itr = v.begin(); itr != v.end(); itr++) {
	cout << *itr << " ";
}*/
