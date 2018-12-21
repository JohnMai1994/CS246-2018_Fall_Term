#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Add dollar sign to all integers
void format_currency(string numbers){
    istringstream input {numbers};
    int number;
    string non_number;

    while (input >> number || ! input.eof()){

        if (input.fail()){
            input.clear();
            input >> non_number;
			cout << non_number << " ";
		} else {
            cout << "$" << number << " ";
        }
    }
    cout << endl;
}

int main(){
    string numbers = "1 2 100 34 25 :) 5 twenty";
    format_currency(numbers);
    return 0;
}
