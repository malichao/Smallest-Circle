#ifndef COMMON_H
#define COMMON_H

namespace smallest_circle {
struct Point {
  double x, y;
  const double Distance(const Point& other) const;
};

struct Circle {
  Circle();

  Circle(const Point& p, const double r);

  Circle(const Point& p1, const Point& p2);

  Circle(const Point& p1, const Point& p2, const Point& p3);

  Point center;
  double radius = 0;
  bool Encloses(const Point& p);
};
}

#endif  // COMMON_H
