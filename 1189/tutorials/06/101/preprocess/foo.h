#ifndef __FOO__H__
#define __FOO__H__

struct Foo{
	static int MAX;
	int n = 9;
};
int Foo::MAX = 42; // causes redefiniton of Foo::MAX if included in multiple .cc files
#endif
