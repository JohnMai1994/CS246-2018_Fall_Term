#include <stdexcept>
#include <unique_ptr>
using namespace std;

// Using RAII to handle resources
int main() {
	try {
        int *arr1 = new int[10];
        int *arr2 = nullptr;
        try { // Ugly fix to code segment 1
            arr2 = new int[20];
        } catch (std::bad_alloc &e) {
            delete arr1;
            throw;
        }
        delete arr1;
        delete arr2;
    } catch(std::bad_alloc &e) {
        // handler
    }
}
