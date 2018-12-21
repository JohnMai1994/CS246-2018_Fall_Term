#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
    int width;
    string dir;
    if (argc-1 == 0) {
      width = 25;
      dir = "-l";
    } else if (argc-1 == 1) {
      string first (argv[1]);
      if (first == "-w") { 
        cerr << "Error, missing width with -w argument" << endl;
        return 1;  
      } else if ((first == "-l")||(first == "-r")||(first == "-c")) {   
       width = 25;
       dir = first;
      }
    } else if (argc -1 == 2) {
      string first (argv[1]);
      if (first != "-w") {
         cerr << "Error, unknown justification style: " << endl;
         return 1;
      } else {
         string second (argv[2]);
         istringstream is_num {second};
         if (!( is_num  >> width)) {
           cerr << "terminate called after throwing an instance of 'std::invalid_argument' what (): stoi" << "\n" << "Aborted" << endl;
         return 1;
         } else {
           dir = "-l";
         }
      }
    } else if (argc -1 >= 3) {
      string first (argv[1]);
      if (first != "-w") {
         cerr << "Error, unknown justification style: " << endl;
         return 1;
      } else {
         string second (argv[2]);
         istringstream is_num {second};
         if (!(is_num >> width)) {
            cerr << "terminate called after throwing an instance of 'std::invalid_argument' what (): stoi" << "\n" << "Aborted" << endl;
         return 1;
         } else {
           string third (argv[3]);
           if (third == "-l") {
             dir = third;
           }else if (third == "-r") {
             dir = third;
           }else if (third == "-c") {
             dir = third;
           }else {
             cerr << "Error, unknown justification style: \"" << argv[3] << "\"" << endl;
             return 1;
           }
         }
      }
    }
   // cout << width << " " << dir << endl;

   string content, line;
   while (!cin.eof()) {   
      getline(cin, line);
      content += " ";
      content += line;
   }   

   istringstream iss (content);
   string word, output;
   output = ""; 
   int output_size, word_size; 
   while (iss >> word) {
      output_size = output.length();
      word_size = word.length(); 

      if (word_size + output_size >= width) {
         int space_left = 0;
         int space_right = 0;
         if ((word_size < width)||(output_size > 0)) {
         if (dir == "-r") {
            space_left = width - output_size;
            string lspace(space_left, ' ');
            string rspace(space_right, ' ');
            cout << lspace << output << rspace << endl;
         } else if (dir == "-l") {
            space_right = width - output_size;
            string lspace(space_left, ' ');
            string rspace(space_right, ' ');
            cout << lspace << output << rspace << endl;
         } else {
            space_left = (width - output_size)/2;
            space_right = width - output_size - space_left;
            string rspace(space_right, ' ');
            string lspace(space_left, ' ');
            cout << lspace << output << rspace << endl;
         }
         }
         output = "";
      }
      output_size = output.length();
      if (word_size + output_size < width) {
         if (output != "") output += " ";
         output += word;
         output_size = output.length();
      } else {
         output = word;
         output_size = output.length();
         while (output_size >= width){
             cout << output.substr(0, width) << endl;
             output = output.substr(width);
             output_size = output.length();
         }
      }   
   } 
   if (output_size > 0) {
      int space_left = 0;
      int space_right = 0;
         if (dir == "-r") {
            space_left = width - output_size;
            string lspace(space_left, ' ');
            string rspace(space_right, ' ');
            cout << lspace << output << rspace << endl;
         } else if (dir == "-l") {
            space_right = width - output_size;
            string lspace(space_left, ' ');
            string rspace(space_right, ' ');
            cout << lspace << output << rspace << endl;
         } else {
            space_left = (width - output_size)/2;
            space_right = width - output_size - space_left;
            string rspace(space_right, ' ');
            string lspace(space_left, ' ');
            cout << lspace << output << rspace  << endl;
         }
   }
 //  std::cout.width(10);  std::cout << std::right << content <<"\n";
  
}
