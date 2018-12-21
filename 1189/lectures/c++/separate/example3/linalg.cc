#include "vec.h"
#include "linalg.h"

int operator*(const Vec &v1, const Vec &v2) {
   return v1.x * v2.x + v1.y * v2.y;
}

int normSquared(const Vec &v) { return v * v; }
