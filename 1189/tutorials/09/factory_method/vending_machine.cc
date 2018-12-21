#include <iostream>

using namespace std;

class Drink {
public:
    virtual string name() = 0;
    virtual ~Drink() {}
};

class Coke : public Drink {
public:
    string name() override { return "coke"; }
};

class Pepsi : public Drink {
public:
    string name() override { return "pepsi"; }
};

class Sprite : public Drink {
public:
    string name() override { return "sprite"; }
};

class VendingMachine {
public:
    virtual Drink *buy() = 0;
    virtual ~VendingMachine() {}
};

class CokeMachine : public VendingMachine {
public:
    Drink *buy() override { return new Coke; }
};

class PepsiMachine : public VendingMachine {
public:
    Drink *buy() override { return new Pepsi; }
};

class SpriteMachine : public VendingMachine {
public:
    Drink *buy() override { return new Sprite; }
};

int main() {
    VendingMachine * machine = new CokeMachine;
    for (int i = 0; i < 9; ++i) {
        if (i == 3) {
            delete machine;
            machine = new PepsiMachine;
        }
        else if (i == 6) {
            delete machine;
            machine = new SpriteMachine;
        }

        Drink *drink = machine->buy();

        cout << drink->name() << endl;

        delete drink;
    }

    delete machine;
}
