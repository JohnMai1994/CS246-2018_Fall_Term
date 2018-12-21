#include <iostream>
using namespace std;

class BadInput {};

class BadNumber : public BadInput {
public:
    string what() {
        return "no number given";
    }
};

int pitcher(int x) {
    if (x < 50) {
        throw BadInput {};
    } else {
        throw BadNumber {};
    }
}

int main() {
    try { // Let's try this block:
        int x;
        cin >> x;
        pitcher(x);
    } catch (BadNumber &b) { // Catch Subclasses before Base class
        cerr << "BadNumber is caught" << endl;
        cerr << "The error is: " << 
            b.what() << endl; // Accessing auxilliary information
    } catch (BadInput &b) {
        cerr << "BadInput is caught" << endl;
    }
}

