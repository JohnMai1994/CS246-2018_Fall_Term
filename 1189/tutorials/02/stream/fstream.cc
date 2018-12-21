#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// This prints the words separated by newlines
void print_in_newline(istream& input, ostream& output){
    string word;
    while ( input >> word ){        
        output << word << endl;
    }
}

int main(){
    ifstream fin {"fstream.in"};
    ofstream fout {"fstream.out", ios_base::app};

    print_in_newline(fin, fout);
	return 0;
}
