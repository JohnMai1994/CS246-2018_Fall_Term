#include <iostream>
#include <initializer_list>
#include <typeinfo>
using namespace std;

class ReverseArray {

    int array[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

public:

    class Iterator{

        int *element;

        Iterator(int *element) : element{element} {}

    public:

        Iterator &operator ++() { // Prefix ++
            --element;
            return *this;
        }

        bool operator !=(const Iterator &other) {
            return element != other.element;
        } 
      
        int &operator *() {
            return *element;
        } 
        
        friend class ReverseArray;
    };

    Iterator begin() {return Iterator(array + 9);}
    Iterator end() {return Iterator(array - 1);}
};

int main() {
    ReverseArray array;
    for (int &i : array) {
        cout << i << endl;
    } 
    return 0;
}
