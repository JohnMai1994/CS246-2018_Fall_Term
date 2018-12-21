#include "vec.h"

Vec operator+(const Vec &v1, const Vec &v2) {
  Vec v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  return v;
}
