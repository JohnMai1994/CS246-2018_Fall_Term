#ifndef _VECTOR_H_
#define _VECTOR_H_

struct Vec {
  int x;
  int y;
};

Vec operator+(const Vec &v1, const Vec &v2);

#endif
