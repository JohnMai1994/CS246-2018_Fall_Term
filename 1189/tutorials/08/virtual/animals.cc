#include <iostream>
#include <string>

using namespace std;

struct Animal {
    virtual bool fly() const = 0; // No implementation for fly
    virtual ~Animal() {}
};

struct Cat : public Animal {};

struct NyanCat final : public Cat {  
    bool fly() const override {
        cout << "NYAN NYAN NYAN NYAN..." << endl;
        return true;
    }

    ~NyanCat() override {cout << "NYAN!" << endl;}
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

    ~Goose() override {cout << "RIP MR. GOOSE" << endl;}
};

int main() {
    // Animal animal; // Cannot create an abstract class
    // Cat cat; // Cannot create an abstract class
    NyanCat nCat;
    Bird bird;
    Goose goose;

    Animal *animal1 = &nCat;
    Animal *animal2 = &goose;  

    animal1->fly();
    animal2->fly();
    cout << endl;
}
