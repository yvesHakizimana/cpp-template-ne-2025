#include <iostream>
#include <ctime>

using namespace std;

/**
 * For Date time  we have two types namely ---> time_t and struct tm for datetime.
 * 
 */
int main(){
    struct tm datetime;
    time_t timestamp;

    datetime.tm_year = 2025-1900;
    datetime.tm_mon = 12 - 1;
    datetime.tm_mday = 17;
    datetime.tm_hour = 12;
    datetime.tm_min = 30;
    datetime.tm_sec = 1;

    timestamp = mktime(&datetime);

    cout << ctime(&timestamp) << endl;
}