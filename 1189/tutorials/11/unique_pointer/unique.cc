#include <memory>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct A{
  string word = "hello";
  
};

struct B: public A{
  B(): A{"world"} {};
};

struct C: public A{
  C(): A{"goodbye"} {};
};

ostream& operator<<(ostream& out, A& a){
  out << a.word;
  return out;
}

unique_ptr<A> getRandom(){
  int choice = rand() % 3;
  unique_ptr<A> p;
  if ( choice == 0 ) p = make_unique<A>();
  else if ( choice == 1 ) p = make_unique<B>();
  else p = make_unique<C>();
  return p;
}

int main(){
  srand(time(NULL));
  for ( int i = 0; i < 10; ++i ){
    unique_ptr<A> a = getRandom();
    cout << *a << endl;
  }
}
