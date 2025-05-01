#include <iostream>

using namespace std;

// Can you tell me the difference between nullptr and NULL?
// nullptr is a keyword introduced in C++11 that represents a null pointer constant.
// It is type-safe and can be used with any pointer type.
// NULL is a macro that is typically defined as 0 or ((void*)0) in C/C++.
// It is not type-safe and can lead to ambiguity in function overloading.
// nullptr is preferred over NULL in modern C++ code for better type safety and clarity.
// Which library do we find the nullptr keyword in?
void func(int){
    cout << "int" << endl;
}


void func(bool*){
    cout << "boolean" << endl;
}


int main(){
    func(nullptr);
    return 0;
}