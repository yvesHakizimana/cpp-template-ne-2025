#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(){
    fstream myFile("example-file.txt");

    string text;

    if(myFile.is_open()){
        cout << "The file is opened successffully" << endl;

        while(getline(myFile, text)){
            cout << text;
        }
    } else {
        cout << "Unable to open the file." << endl;
    }


}