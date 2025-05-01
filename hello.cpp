#include <iostream>
#include <string>  // Needed for string type

using namespace std;

enum Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

int main() {
	int x = 10;
	int *ref = &x;
	cout << "Original x: " << x << endl;
	cout << "Address of x: " << ref << endl;
	cout << "Value pointed to by ref: " << *ref << endl;
}