#ifndef COMMON_H
#define COMMON_H

namespace smallest_circle {
struct Point {
  double x, y;
};

struct Circle {
  Point center;
  double radius;
};
}

#endif  // COMMON_H
