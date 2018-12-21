#include <iostream>
#include <string>

using namespace std;

struct Animal {
    virtual bool fly() const { return false; }
};

struct Cat : public Animal {};

struct NyanCat final : public Cat {  
    bool fly() const override {
        cout << "NYAN NYAN NYAN NYAN..." << endl;
        return true;
    }
};

struct Bird : public Animal {  
    bool fly() const override {
        return true;
    }
};

struct Goose final : public Bird { 
    bool fly() const override {
        cout << "THANK MR. GOOSE" << endl;
        return true;
    }
};

int main() {
    cout << boolalpha;
    cin >> noskipws;

    Cat cat;
    NyanCat nCat;
    Bird bird;
    Goose goose;

    char newline_char;

    cout << "Nyan Cat through Animal object. Can it fly?" << endl;
    Animal animal = nCat;
    cout << "Press enter to find out!" << endl;
    cin >> newline_char;
    cout << animal.fly() << endl << endl;

    cout << "Nyan Cat through Animal pointer. Can it fly?" << endl;
    Animal *animalPoint = &nCat;
    cout << "Press enter to find out!" << endl;
    cin >> newline_char;
    cout << animalPoint->fly() << endl << endl;

    cout << "Nyan Cat through Animal reference. Can it fly?" << endl;
    Animal &animalRef = nCat;
    cout << "Press enter to find out!" << endl;
    cin >> newline_char;
    cout << animalRef.fly() << endl << endl;
    
    cout << "Goose through Animal reference. Can it fly?" << endl;
    Animal &goo1 = goose;
    cout << "Press enter to find out!" << endl;
    cin >> newline_char;
    cout << goo1.fly() << endl << endl;

    cout << "Goose through Bird object. Can it fly?" << endl;
    Bird goo2 = goose;
    cout << "Press enter to find out!" << endl;
    cin >> newline_char;
    cout << goo2.fly() << endl << endl;    
}
