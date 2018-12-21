#include <memory>
#include <stdexcept>
using namespace std;

struct Wrapper {
    int *arr = nullptr;
    int length;

    Wrapper(int length) : length{length} {
        arr = new int[length];
    }

    ~Wrapper() {
        delete arr;
    }
};

int main() {
    try {
        Wrapper         arr1 {10};
        unique_ptr<int> arr2 {new int[20]};
    } catch (std::bad_alloc &e) {
        // handler
    }
}
