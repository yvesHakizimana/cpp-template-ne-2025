#include <iostream>

using namespace std;

template <typename T>
T max(T a, T b){
    return (a > b) ? a : b;
}


// in c++ we can have like function templates and also the  class templates.
template <typename T>
class Box {
    private:
        T content;
    public:
        void set(T value) { content = value;}
        T get() const { return content;}
};