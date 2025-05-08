#include <iostream>
using namespace std;

class Animal {
    public:
        void eat() {
            cout << "The Animal is eating " << endl;
        }
};

class Dog:  public Animal {
    public:
        void bark() {
            cout << "Barking" << endl;
        }
};


/**
 * 
 * Point to note is this, 
 * when you didn't specify the access modifier 
 * by the default on the class we will be having 
 * 
 * the access will be private, 
 * 
 * but if it's a struct it will be public.
 * 
 * class --> default inheritance is private
 * struct --> default inheritance is public
 * 
 */

int main(){
    Dog d;
    d.eat();
    d.bark();
    return 0;
}