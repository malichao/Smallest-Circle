#include "SmallestCircle/smallest_circle.h"
#include <algorithm>
namespace smallest_circle {

// TODO: test the following specail cases:
//      1 point: return itself and 0 radius
//      2 points: return the middle of 2 points as center and half of the length
//                as radius
//      3 points: triangles, return should be circumcircle
//      3 points on a line: similar to 2 points
Circle SmallestCircle::FindSmallestCircle(const std::vector<Point> &points) {
  // Section 4.4, random permutation makes the algorithm an average running time
  // O(n)
  std::random_shuffle(points.begin(), points.end());
}

Circle SmallestCircle::FindSmallestCircle(const std::vector<Point> &points,
                                          const Point &q) {}

Circle SmallestCircle::FindSmallestCircle(const std::vector<Point> &points,
                                          const Point &q1, const Point &q2) {}
}
