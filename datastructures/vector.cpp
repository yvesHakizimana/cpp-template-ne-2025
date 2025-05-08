#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<string> cars = {"Totoya", "Benz"};

    for (string car: cars){
        cout << car  << "\n";
    }
}

/**
 * 
 * Some notes about the vector datastructure
 * (Resizable array) this can be resized
 * 
 * vector<datatype> name_of_the_strucuture;
 * 
 * accessing the elements can be done in this way
 * if we had vector<string> cars;
 * 
 * then accessing individual cars can be like this 
 * cout << cars[0]; or cout << cars[1]
 * 
 * getting the first element(cars.front()) --> Getting the front element
 * 
 * getting the last element(cars.back()) --> Getting the last element;
 * 
 * getting the element at specific index --> .at can be used
 * 
 * we can use .push_back() to add an element at the back of the array or .pop_back to remove the 
 * element from the back.
 * 
 * 
 * getting the vector size we can use .size(),
 * .empty() to check whether the vector is is empty or not.(returns 1 or 0 to mean false / true.)
 * 
 * 
 * 
 */