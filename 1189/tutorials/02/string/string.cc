#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv){

    std::string my_string = argv[1];
    cout << "The string is: " << my_string << endl;
    cout << "The fifth character in the string is: " << my_string[4] << endl;
    cout << "The length of the string is: " << my_string.length() << endl;
    cout << (my_string == "hello" ? "This is a greeting" : "This is not a greeting") << endl;
    cout << my_string.substr(1, 2) << "is a substring of the string" << endl; 
    cout << my_string + "!!" << endl;

	return 0;
}
