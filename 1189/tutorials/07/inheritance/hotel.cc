#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Guest {
    string name;
    int moneyInPocket;
};

class Hotel {
    
    struct Room {
        int roomNumber = 0;
    };

    vector<Guest> guests;        // The Hotel has-a (or many) guests
    vector<Room> rooms;          // The Hotel own-a (or many) rooms

//protected:
    
    int rating = 3;

public:
    
     Hotel (int rating) : rating{rating} {} 

     void addGuest(Guest g) { guests.push_back(g); }

     void printGuestList() { for (auto g : guests) cout << g.name << endl; }

};

class  LuxuryHotel : public Hotel{ // LuxuryHotel is-a Hotel

    int numOfSwimmingPool = 1;

public:

    LuxuryHotel(int rating, int numOfSwimmingPool) : Hotel{rating}, numOfSwimmingPool{numOfSwimmingPool} {}    
 
    void describe() {
        cout << "Our luxury hotel has " << 
            // rating << " stars rating and " << // rating is private
            numOfSwimmingPool << " swimming pool." << endl;
    }

};

int main() {
    LuxuryHotel h {5, 3};
    h.addGuest({"Jason", 800});
    h.addGuest({"Amy", 1000});
    h.addGuest({"Tony", 1000000000});
    h.printGuestList();  
    cout << endl;
    h.describe();
    return 0;
}
