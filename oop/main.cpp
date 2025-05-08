#include <iostream>
#include <string>

using namespace std;

class MyClass {
    public:
        // Higlighting the default constructor.
        MyClass(){
            cout << "Hello World" << endl;
        }
};


// what is the c++  inheritance
class Vehicle {
    public:
        string brand = "Ford";
        void honk(){
            cout << "Tuut, tuut! \n";
        }
};

class Car : protected Vehicle {
    public:
        string model = "Mustang";
};


int main(){
    Car myCar;
    myCar.honk();
    return 0;
}