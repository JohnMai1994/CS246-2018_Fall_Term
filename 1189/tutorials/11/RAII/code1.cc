#include <stdexcept>
using namespace std;

int main() {
	try {
        int *arr1 = new int[10];
        int *arr2 = new int[20]; // what if operator new throws
        delete arr1;
        delete arr2;
    } catch(std::bad_alloc &e) {
        // handler
    }
}
