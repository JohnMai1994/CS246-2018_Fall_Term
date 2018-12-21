#include "vec.h"

Vec operator+(const Vec &v1, const Vec &v2) {
  return {v1.x + v2.x, v1.y + v2.y};
}
