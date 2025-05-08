#include "utils.h"
#include <iostream>

using namespace std;

int main(){
    csv::Table patients = {
        {"ID", "Name", "Age"},
        {"P001", "John Doe", "45"},
        {"P002", "Jane Smith", "32"}
    };

    if (csv::write("patients.csv", patients)){
        cout << "Successfully wrote data to patients.csv\n";
    }

    csv::Record newPatient = {"P003","Bob Johnson", "28"};
    if(csv::append("patients.csv", newPatient)){
        cout << "Succefully appended new patient\n";
    }

    csv::Table data = csv::read("patients.csv");


    // display the data
    for (const auto& row: data){
        for (const auto& cell: row){
            cout << cell << "\t";
        }
        cout << "\n";
    }


}