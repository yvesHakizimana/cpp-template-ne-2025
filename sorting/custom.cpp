#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>


using namespace std;

class Employee {
    public:
        string firstName;
        string lastName;
        string email;
        double salary;
        int age;
        Employee (string fname, string lname, string mail, double sal, int a) :firstName(fname), lastName(lname), email(mail), salary(sal), age(a) {}
        bool operator<(const Employee& other){
            return tie(firstName, lastName, email, salary, age) < tie(other.firstName, other.lastName, other.email, other.salary, other.age);
        }

};


int main(){
    vector<Employee> employees = {
        {"John", "Doe", "john@example.com", 50000, 30},
        {"Alice", "Smith", "alice@example.com", 60000, 25},
        {"Bob", "Smith", "bob@example.com", 55000, 35}
    }; 

    // sort the array of them.
    sort(employees.begin(), employees.end());

    for(auto &e : employees){
        cout
            << e.firstName << " "
            << e.lastName  << ", age="
            << e.age << ", $"
            << e.salary << "\n";
    }

    return 0;


}