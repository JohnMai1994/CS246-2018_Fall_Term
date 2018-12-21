#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[]){
   /*
   int n;
   string s (argv[1]);
   string a (argv[2]);
   if (a == "-w") cout << a << endl;
   istringstream iss (s);
   if (iss >> n) cout << n << endl;
   cout << "love you"<< s[0] << endl;

   string k = "what the fuck?";
   cout << k.size() << endl;
   std::cout.width(226); std::cout << std::right << k << '\n';
   */
   string str2 = "what the fuck??";
   string b = str2.substr(3,5);
   cout << b << endl;
   return 0;
}

