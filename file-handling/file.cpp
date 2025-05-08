#include <iostream>
#include <fstream>
#include <string>


/**
 * Creating the files in cpp involves the library #include <fstream>
 * 
 * and then we also use 
 * 
 * ofstream for creating and writing to the files.
 * ifstream for reading from the files.
 * fstream which is the combination of ofstream and ifstream which creates, reads and writes to a file.
 * 
 */
using namespace std;

int main(){
    // Create and open a text file.
    ofstream myFile("example-file.txt");

    // Check if the file was successfully opened.
    if(myFile.is_open()){
        // Write to the file.
        myFile << "This is the first line \n";
        myFile << "This is the second line \n";

        string name;
        int age;

        cout << "Enter your name: " ;
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;

        myFile << "Name: " << name << endl;
        myFile << "Age: " << age << endl;

        //Cose the file.
        myFile.close();
    } else {
        cerr << "Unable to open the file " << endl;
        return 1;
    }
    return 0;
}