#ifndef ___ARRRRRAAAAAAYYY___HHH__
#define ___ARRRRRAAAAAAYYY___HHH__

#include <string>
#include <utility>

using namespace std;

struct Array{
	int r = 1;
	int c = 1;
	int** arr = nullptr;

	Array(int c = 1, int r = 1): c{c}, r{r},
		arr{ new int*[c] } {
		for ( int i = 0; i < c; ++ i){
			arr[i] = new int[r];
		}
	}

/*
	void resize(){
		if ( cap == size ){
			cap *= 2;
			string* temp = new string[cap];
			for ( int i = 0; i < size; ++i ){
				temp[i] = arr[i];
			}
			delete arr;
			arr = temp;
		}
	}
	void addToBack(const string& s){
		resize();
		arr[size++] = s;
	}
*/

	void swap(Array& o){
		using std::swap;
		swap(r, o.r);
		swap(c, o.c);
		swap(arr, o.arr);
	}

	Array(const Array& other): c{other.c},
		r{other.r},
		arr{ new int*[c] }{


		for (int i = 0; i < c; ++i ){
			arr[i] = new int[r];
			for ( int j = 0; j < r; ++j ){
				arr[i][j] = o.arr[i][j];
			}
		}
	}

	Array(Array&& other): cap{other.cap},
		size{other.size}, arr{other.arr}{
		other.arr = nullptr;
		other.c = 0;
	}
	
	void foo(Arr a){
		// .. do some things
		// a will be deleted
	}

	Arr foo2(Arr a){
		// .. do some things
		return a; // a may be elided
	}

	~Array() {
		for ( int i = 0; i < c; ++i) delete[] arr[i];
		delete[] arr;
	}

	Array& operator=(const Array& other){
		Array copy{other}; //copy ctor
		swap(copy);
		return *this; // copy's dtor is run
	}

	Array& operator=(Array&& other){
		swap(other);
		return *this;
	}

};

#endif
