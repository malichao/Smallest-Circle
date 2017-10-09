#ifndef SMALLEST_CIRCLE_H
#define SMALLEST_CIRCLE_H
#include <vector>
#include <SmallestCircle/common.h>
namespace smallest_circle {

// An implementation of the Smallest Enclosing Discs algorithm described in the
// book Computational Geometry, section 4.7
class SmallestCircle {
 public:
  static Circle FindSmallestCircle(const std::vector<Point>& points);

 private:
  static Circle FindSmallestCircle(const std::vector<Point>& points,
                                   const Point& q);

  static Circle FindSmallestCircle(const std::vector<Point>& points,
                                   const Point& q1, const Point& q2);
};
}

#endif  // SMALLEST_CIRCLE_H
