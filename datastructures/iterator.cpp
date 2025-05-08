/**
 * Brief Notes about also the iterators
 * C++ iterators are called iterators because they iterate in the objects.alignas
 * 
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    vector<string>::iterator it;

    for (it = cars.begin(); it != cars.end(); ++it){
        cout << *it << endl;
    }

    return 0;
}