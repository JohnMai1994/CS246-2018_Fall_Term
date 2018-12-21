#include <iostream>
#include <vector>
using namespace std;

// iterate a vector in four different ways
int main(){
    vector<int> v {2, 3, 5, 7, 11, 13};

    for (int i = 0; i < 6; ++i)
        cout << v[i] << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    for (int i : v)
        cout << i << endl;
    
}
