#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

struct Vec3d{
  int x;
  int y;
  int z;
};

// Vector addition
Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs);
// Cross product
Vec3d operator*(const Vec3d& lhs, const Vec3d& rhs);

// io
std::ostream& operator<<(std::ostream&, const Vec3d& rhs);
std::istream& operator>>(std::istream&, Vec3d& rhs);
#endif
