#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void recurse ( ostream& out ){
	string s;
	if (getline(cin, s)){
		recurse(out);
		out << s << endl;
	}
}

int main(){
//	ifstream ifs{"test1.in"};
//	ofstream ofs{"test1.out"};
	string s;
	ostringstream oss;
	oss << endl;
	string EOL = oss.str();
	cout << EOL;
}

